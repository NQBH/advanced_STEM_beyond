#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set> // Still useful for mapToExtended to collect unique edges before expanding
#include <algorithm> // For std::min and std::max

using namespace std;

// Graph representations
struct AdjacencyMatrix {
    vector<vector<int>> matrix; // Stores count of edges between vertices
    int n;
};

struct AdjacencyList {
    vector<vector<int>> adj;
    int n;
};

struct ExtendedAdjacencyList {
    vector<vector<int>> incoming; // Stores indices to 'edges'
    vector<vector<int>> outgoing; // Stores indices to 'edges'
    vector<pair<int, int>> edges; // Stores all individual edge instances (u,v)
    int n, m; // n = number of vertices, m = number of edges (total instances)
};

struct AdjacencyMap {
    // For each vertex 'u', stores a list of pairs: {neighbor_v, canonical_edge_tuple (min(u,v), max(u,v))}
    unordered_map<int, vector<pair<int, pair<int, int>>>> outgoing;
    unordered_map<int, vector<pair<int, pair<int, int>>>> incoming;
    int n; // Number of vertices
    int m; // Total number of edge instances
};

// Enum for current representation
enum Representation {
    ADJ_LIST,
    ADJ_MATRIX,
    EXT_ADJ_LIST,
    ADJ_MAP
};

// Global variables to track current state
AdjacencyList current_list;
AdjacencyMatrix current_matrix;
ExtendedAdjacencyList current_extended;
AdjacencyMap current_map;
Representation current_rep = ADJ_LIST;


// ========== ALL 12 CONVERSION FUNCTIONS FOR GENERAL GRAPH (ALLOWS LOOPS AND MULTIPLE EDGES) ==========

// 1. Adjacency List ↔ Adjacency Matrix
// Converts an AdjacencyList representation to an AdjacencyMatrix.
// For general graphs, the matrix cells store the count of edges between vertices, including loops.
AdjacencyMatrix listToMatrix(const AdjacencyList& list) {
    AdjacencyMatrix matrix;
    matrix.n = list.n;
    matrix.matrix.resize(matrix.n, vector<int>(matrix.n, 0)); // Initialize with 0

    // Iterate through each vertex's adjacency list
    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            // Increment the count for the edge (i, j).
            // For undirected graphs, if (u,v) is added, (v,u) is also added to the list.
            // This naturally increments both matrix[u][v] and matrix[v][u].
            // For loops (i,i), matrix[i][i] is incremented.
            matrix.matrix[i][j]++;
        }
    }
    return matrix;
}

// Converts an AdjacencyMatrix representation to an AdjacencyList.
// For general graphs, if matrix[i][j] is k, then 'j' is added k times to list.adj[i].
AdjacencyList matrixToList(const AdjacencyMatrix& matrix) {
    AdjacencyList list;
    list.n = matrix.n;
    list.adj.resize(list.n);

    // Iterate through all cells of the matrix
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            // Add 'j' to 'i's list 'matrix.matrix[i][j]' times
            for (int k = 0; k < matrix.matrix[i][j]; k++) {
                list.adj[i].push_back(j);
            }
        }
    }
    return list;
}

// 2. Adjacency Matrix ↔ Extended Adjacency List
// Converts an AdjacencyMatrix to an ExtendedAdjacencyList.
// Each edge instance (based on count in matrix) is added to ext.edges.
ExtendedAdjacencyList matrixToExtended(const AdjacencyMatrix& matrix) {
    ExtendedAdjacencyList ext;
    ext.n = matrix.n;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    ext.m = 0; // Initialize total edge count

    // Collect all edge instances
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            // For undirected graphs, we only process (i,j) where i <= j
            // to avoid double-counting the same undirected edge instance when adding to ext.edges.
            // This also correctly handles loops (i,i) as i <= i is true.
            if (i <= j) {
                int edge_count = matrix.matrix[i][j];
                for (int k = 0; k < edge_count; k++) {
                    ext.edges.push_back({i, j}); // Add the edge instance
                    int edge_idx = ext.edges.size() - 1; // Index of the newly added edge

                    ext.outgoing[i].push_back(edge_idx);
                    ext.incoming[j].push_back(edge_idx);

                    if (i != j) { // For non-loop edges, also add reverse connections
                        ext.outgoing[j].push_back(edge_idx);
                        ext.incoming[i].push_back(edge_idx);
                    }
                    ext.m++; // Increment total edge count for each instance
                }
            }
        }
    }
    return ext;
}

// Converts an ExtendedAdjacencyList representation to an AdjacencyMatrix.
// Each edge in ext.edges increments the corresponding matrix cell.
AdjacencyMatrix extendedToMatrix(const ExtendedAdjacencyList& ext) {
    AdjacencyMatrix matrix;
    matrix.n = ext.n;
    matrix.matrix.resize(matrix.n, vector<int>(matrix.n, 0)); // Initialize with 0

    // Iterate through all individual edge instances
    for (const auto& edge : ext.edges) {
        int u = edge.first;
        int v = edge.second;
        matrix.matrix[u][v]++;
        if (u != v) { // For undirected graph, also increment the reverse for non-loops
            matrix.matrix[v][u]++;
        }
    }
    return matrix;
}

// 3. Adjacency Matrix ↔ Adjacency Map
// Converts an AdjacencyMatrix to an AdjacencyMap.
// The map stores the canonical edge tuple for each connection.
AdjacencyMap matrixToMap(const AdjacencyMatrix& matrix) {
    AdjacencyMap map;
    map.n = matrix.n;
    map.m = 0; // Initialize total edge count

    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            int edge_count = matrix.matrix[i][j];
            if (edge_count > 0) {
                pair<int, int> canonical_edge = {min(i, j), max(i, j)};
                for (int k = 0; k < edge_count; ++k) {
                    map.outgoing[i].push_back({j, canonical_edge});
                    map.incoming[j].push_back({i, canonical_edge}); // For undirected graph
                }
            }
        }
    }
    // Count m: Sum up the sizes of all vectors in outgoing and divide by 2.
    // This correctly counts loops as 1 edge (they appear twice in the sum, once for outgoing[i] and once for incoming[i]).
    for (const auto& entry : map.outgoing) {
        map.m += entry.second.size();
    }
    map.m /= 2;
    return map;
}

// Converts an AdjacencyMap to an AdjacencyMatrix.
// The matrix cells are populated with counts based on the map's stored edge instances.
AdjacencyMatrix mapToMatrix(const AdjacencyMap& map) {
    AdjacencyMatrix matrix;
    matrix.n = map.n;
    matrix.matrix.resize(matrix.n, vector<int>(matrix.n, 0));

    // Iterate through outgoing mappings
    for (const auto& vertex_pair : map.outgoing) {
        int u = vertex_pair.first;
        for (const auto& edge_info : vertex_pair.second) {
            int v = edge_info.first;
            matrix.matrix[u][v]++;
        }
    }
    return matrix;
}

// 4. Adjacency List ↔ Extended Adjacency List
// Converts an AdjacencyList to an ExtendedAdjacencyList.
// Uses a temporary map to count undirected edge multiplicities (canonical form: u,v) before populating ext.edges.
ExtendedAdjacencyList listToExtended(const AdjacencyList& list) {
    ExtendedAdjacencyList ext;
    ext.n = list.n;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    ext.m = 0; // Initialize total edge count

    // Use a map to count the multiplicity of each canonical edge (u,v)
    map<pair<int, int>, int> edge_multiplicity;

    for (int i = 0; i < list.n; ++i) {
        for (int j : list.adj[i]) {
            pair<int, int> canonical_edge = {min(i, j), max(i, j)};
            edge_multiplicity[canonical_edge]++;
        }
    }

    // Populate ext.edges and incoming/outgoing lists based on counted multiplicities
    for (const auto& entry : edge_multiplicity) {
        int u = entry.first.first;
        int v = entry.first.second;
        int count_in_adj_list_sum = entry.second; // Total times (u,v) or (v,u) appeared in adj lists

        int actual_edge_count;
        if (u == v) { // It's a loop (i,i)
            // Each loop (i,i) appears once in adj[i]
            actual_edge_count = count_in_adj_list_sum;
        } else { // It's a non-loop edge (u,v)
            // Each (u,v) edge appears in adj[u] and adj[v], so divide by 2
            actual_edge_count = count_in_adj_list_sum / 2;
        }

        for (int k = 0; k < actual_edge_count; ++k) {
            ext.edges.push_back({u, v}); // Add the undirected edge instance
            int edge_idx = ext.edges.size() - 1;

            ext.outgoing[u].push_back(edge_idx);
            ext.incoming[v].push_back(edge_idx);

            if (u != v) { // Only add reverse for non-loops
                ext.outgoing[v].push_back(edge_idx);
                ext.incoming[u].push_back(edge_idx);
            }
            ext.m++; // Increment total edge count for each instance
        }
    }
    return ext;
}

// Converts an ExtendedAdjacencyList to an AdjacencyList.
// Each edge in ext.edges is added to the adjacency list.
AdjacencyList extendedToList(const ExtendedAdjacencyList& ext) {
    AdjacencyList list;
    list.n = ext.n;
    list.adj.resize(list.n);

    // Iterate through all individual edge instances
    for (const auto& edge : ext.edges) {
        int u = edge.first;
        int v = edge.second;
        list.adj[u].push_back(v);
        if (u != v) { // For undirected graph, add reverse if not self-loop
            list.adj[v].push_back(u);
        }
    }
    return list;
}

// 5. Adjacency List ↔ Adjacency Map
// Converts an AdjacencyList to an AdjacencyMap.
// Populates the map with neighbor and canonical edge tuple for each connection.
AdjacencyMap listToMap(const AdjacencyList& list) {
    AdjacencyMap map;
    map.n = list.n;
    map.m = 0; // Initialize total edge count

    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            // Create canonical edge tuple (min, max)
            pair<int, int> canonical_edge = {min(i, j), max(i, j)};

            map.outgoing[i].push_back({j, canonical_edge});
            map.incoming[j].push_back({i, canonical_edge}); // For undirected graph
        }
    }
    // Count m: Sum up the sizes of all vectors in outgoing and divide by 2.
    // This correctly counts loops as 1 edge.
    for (const auto& entry : map.outgoing) {
        map.m += entry.second.size();
    }
    map.m /= 2;
    return map;
}

// Converts an AdjacencyMap to an AdjacencyList.
// Each edge (u,v) in the map results in 'v' being added to list.adj[u].
AdjacencyList mapToList(const AdjacencyMap& map) {
    AdjacencyList list;
    list.n = map.n;
    list.adj.resize(list.n);

    // Iterate through outgoing mappings
    for (const auto& vertex_pair : map.outgoing) {
        int u = vertex_pair.first;
        for (const auto& edge_info : vertex_pair.second) {
            int v = edge_info.first;
            list.adj[u].push_back(v);
        }
    }
    return list;
}

// 6. Extended Adjacency List ↔ Adjacency Map
// Converts an ExtendedAdjacencyList to an AdjacencyMap.
// Populates the map with neighbor and canonical edge tuple for each connection.
AdjacencyMap extendedToMap(const ExtendedAdjacencyList& ext) {
    AdjacencyMap map;
    map.n = ext.n;
    map.m = ext.m; // m is already correctly counted in ExtendedAdjacencyList

    for (const auto& edge_tuple : ext.edges) {
        int u = edge_tuple.first;
        int v = edge_tuple.second;
        pair<int, int> canonical_edge = {min(u, v), max(u, v)};

        map.outgoing[u].push_back({v, canonical_edge});
        map.incoming[v].push_back({u, canonical_edge}); // For undirected graph
    }
    return map;
}

// Converts an AdjacencyMap to an ExtendedAdjacencyList.
// Expands the map's stored edge instances into ext.edges.
ExtendedAdjacencyList mapToExtended(const AdjacencyMap& map) {
    ExtendedAdjacencyList ext;
    ext.n = map.n;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    ext.m = 0; // Initialize total edge count

    // Use a temporary map to count occurrences of each canonical edge (u,v)
    std::map<pair<int, int>, int> canonical_edge_counts;

    for (const auto& vertex_pair : map.outgoing) {
        for (const auto& edge_info : vertex_pair.second) {
            pair<int, int> canonical_edge = edge_info.second;
            canonical_edge_counts[canonical_edge]++;
        }
    }

    // Now, populate ext.edges and incoming/outgoing lists
    for (const auto& entry : canonical_edge_counts) {
        int u_canonical = entry.first.first;
        int v_canonical = entry.first.second;
        int count_in_map_outgoing_sum = entry.second;

        int actual_edge_count;
        if (u_canonical == v_canonical) { // It's a loop (i,i)
            // A loop (i,i) appears once in map.outgoing[i]
            actual_edge_count = count_in_map_outgoing_sum;
        } else { // It's a non-loop edge (u,v)
            // A non-loop (u,v) appears in map.outgoing[u] and map.outgoing[v], so divide by 2
            actual_edge_count = count_in_map_outgoing_sum / 2;
        }

        for (int k = 0; k < actual_edge_count; ++k) {
            ext.edges.push_back({u_canonical, v_canonical});
            int edge_idx = ext.edges.size() - 1;

            ext.outgoing[u_canonical].push_back(edge_idx);
            ext.incoming[v_canonical].push_back(edge_idx);

            if (u_canonical != v_canonical) {
                ext.outgoing[v_canonical].push_back(edge_idx);
                ext.incoming[u_canonical].push_back(edge_idx);
            }
            ext.m++;
        }
    }
    return ext;
}

// Display functions
void displayMatrix(const AdjacencyMatrix& matrix) {
    cout << "Adjacency Matrix:\n";
    cout << "   ";
    for (int i = 0; i < matrix.n; i++) {
        cout << i << " ";
    }
    cout << "\n";

    for (int i = 0; i < matrix.n; i++) {
        cout << i << "  ";
        for (int j = 0; j < matrix.n; j++) {
            cout << matrix.matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void displayList(const AdjacencyList& list) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < list.n; i++) {
        cout << i << ": ";
        for (int j : list.adj[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void displayExtended(const ExtendedAdjacencyList& ext) {
    cout << "Extended Adjacency List:\n";
    cout << "Total Edges (m): " << ext.m << "\n";
    cout << "Edges (u,v) and their indices:\n";
    for (int i = 0; i < ext.edges.size(); i++) {
        cout << "  Edge " << i << ": (" << ext.edges[i].first << "," << ext.edges[i].second << ")\n";
    }

    cout << "Outgoing edges (indices):\n";
    for (int i = 0; i < ext.n; i++) {
        cout << i << ": ";
        for (int edge_idx : ext.outgoing[i]) {
            cout << edge_idx << " ";
        }
        cout << "\n";
    }

    cout << "Incoming edges (indices):\n";
    for (int i = 0; i < ext.n; i++) {
        cout << i << ": ";
        for (int edge_idx : ext.incoming[i]) {
            cout << edge_idx << " ";
        }
        cout << "\n";
    }
}

void displayMap(const AdjacencyMap& map) {
    cout << "Adjacency Map:\n";
    cout << "Total Edges (m): " << map.m << "\n";
    cout << "Outgoing mappings:\n";
    for (int i = 0; i < map.n; i++) {
        cout << i << ": ";
        auto it = map.outgoing.find(i);
        if (it != map.outgoing.end()) {
            // Sorting for consistent output, optional but good for readability
            vector<pair<int, pair<int, int>>> sorted_edges = it->second;
            std::sort(sorted_edges.begin(), sorted_edges.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first < b.first;
                if (a.second.first != b.second.first) return a.second.first < b.second.first;
                return a.second.second < b.second.second;
            });
            for (auto& p : sorted_edges) {
                cout << "(" << p.first << "->" << p.second.first << "," << p.second.second << ") ";
            }
        }
        cout << "\n";
    }

    cout << "Incoming mappings:\n";
    for (int i = 0; i < map.n; i++) {
        cout << i << ": ";
        auto it = map.incoming.find(i);
        if (it != map.incoming.end()) {
            // Sorting for consistent output, optional but good for readability
            vector<pair<int, pair<int, int>>> sorted_edges = it->second;
            std::sort(sorted_edges.begin(), sorted_edges.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first < b.first;
                if (a.second.first != b.second.first) return a.second.first < b.second.first;
                return a.second.second < b.second.second;
            });
            for (auto& p : sorted_edges) {
                cout << "(" << p.first << "->" << p.second.first << "," << p.second.second << ") ";
            }
        }
        cout << "\n";
    }
}

// Function to display current representation
void displayCurrentRepresentation() {
    cout << "\n=== DO THI HIEN TAI ===";
    switch (current_rep) {
        case ADJ_LIST:
            cout << " (Adjacency List)\n";
            displayList(current_list);
            break;
        case ADJ_MATRIX:
            cout << " (Adjacency Matrix)\n";
            displayMatrix(current_matrix);
            break;
        case EXT_ADJ_LIST:
            cout << " (Extended Adjacency List)\n";
            displayExtended(current_extended);
            break;
        case ADJ_MAP:
            cout << " (Adjacency Map)\n";
            displayMap(current_map);
            break;
    }
    cout << "\n";
}

// Function to validate conversion choice
bool isValidConversion(int choice) {
    switch (choice) {
        case 1: // Display current
            return true;
        case 2: // AL -> AM
            return current_rep == ADJ_LIST;
        case 3: // AL -> EAL
            return current_rep == ADJ_LIST;
        case 4: // AL -> AMap
            return current_rep == ADJ_LIST;
        case 5: // AM -> AL
            return current_rep == ADJ_MATRIX;
        case 6: // AM -> EAL
            return current_rep == ADJ_MATRIX;
        case 7: // AM -> AMap
            return current_rep == ADJ_MATRIX;
        case 8: // EAL -> AL
            return current_rep == EXT_ADJ_LIST;
        case 9: // EAL -> AM
            return current_rep == EXT_ADJ_LIST;
        case 10: // EAL -> AMap
            return current_rep == EXT_ADJ_LIST;
        case 11: // AMap -> AL
            return current_rep == ADJ_MAP;
        case 12: // AMap -> AM
            return current_rep == ADJ_MAP;
        case 13: // AMap -> EAL
            return current_rep == ADJ_MAP;
        case 14: // Exit
            return true;
        default:
            return false;
    }
}

// Function to get representation name
string getRepName(Representation rep) {
    switch (rep) {
        case ADJ_LIST: return "Adjacency List";
        case ADJ_MATRIX: return "Adjacency Matrix";
        case EXT_ADJ_LIST: return "Extended Adjacency List";
        case ADJ_MAP: return "Adjacency Map";
        default: return "Unknown";
    }
}

int main() {
    cout << "=== CHUONG TRINH CHUYEN DOI BIEU DIEN DO THI TONG QUAT (CHO PHEP DA CANH VA KHUYEN) ===\n\n";

    int n;
    int m_input; // Use a different variable name to avoid confusion with current_list.m
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m_input;

    current_list.n = n;
    current_list.adj.resize(n);

    cout << "Nhap " << m_input << " canh (dinh dau dinh cuoi):\n";
    for (int i = 0; i < m_input; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Canh (" << u << "," << v << ") khong hop le. Dinh phai nam trong khoang [0, " << n-1 << "]. Bo qua canh nay.\n";
            i--; // Decrement counter to re-ask for this edge
            continue;
        }
        // Removed the check for u == v, as loops are now allowed
        current_list.adj[u].push_back(v);
        current_list.adj[v].push_back(u); // Undirected graph
    }

    while (true) {
        cout << "\n=== MENU CHUYEN DOI ===\n";
        cout << "1. Hien thi do thi hien tai\n";
        cout << "=== ADJACENCY LIST CONVERSIONS ===\n";
        cout << "2. AL -> Adjacency Matrix\n";
        cout << "3. AL -> Extended Adjacency List\n";
        cout << "4. AL -> Adjacency Map\n";
        cout << "\n=== ADJACENCY MATRIX CONVERSIONS ===\n";
        cout << "5. AM -> Adjacency List\n";
        cout << "6. AM -> Extended Adjacency List\n";
        cout << "7. AM -> Adjacency Map\n";
        cout << "\n=== EXTENDED ADJACENCY LIST CONVERSIONS ===\n";
        cout << "8. EAL -> Adjacency List\n";
        cout << "9. EAL -> Adjacency Matrix\n";
        cout << "10. EAL -> Adjacency Map\n";
        cout << "\n=== ADJACENCY MAP CONVERSIONS ===\n";
        cout << "11. AMap -> Adjacency List\n";
        cout << "12. AMap -> Adjacency Matrix\n";
        cout << "13. AMap -> Extended Adjacency List\n";
        cout << "\n14. Thoat\n";
        cout << "Chon: ";

        int choice;
        cin >> choice;

        if (!isValidConversion(choice)) {
            cout << "\nLOI: Khong the chuyen doi! Do thi hien tai dang o dang "
                 << getRepName(current_rep) << " nhung ban chon chuyen doi tu dang khac.\n";
            cout << "Vui long chon lai!\n";
            continue;
        }

        switch (choice) {
            case 1:
                displayCurrentRepresentation();
                break;
            case 2: {
                current_matrix = listToMatrix(current_list);
                current_rep = ADJ_MATRIX;
                cout << "\nDa chuyen doi thanh cong: Adjacency List -> Adjacency Matrix\n";
                displayCurrentRepresentation();
                break;
            }
            case 3: {
                current_extended = listToExtended(current_list);
                current_rep = EXT_ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Adjacency List -> Extended Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 4: {
                current_map = listToMap(current_list);
                current_rep = ADJ_MAP;
                cout << "\nDa chuyen doi thanh cong: Adjacency List -> Adjacency Map\n";
                displayCurrentRepresentation();
                break;
            }
            case 5: {
                current_list = matrixToList(current_matrix);
                current_rep = ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Adjacency Matrix -> Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 6: {
                current_extended = matrixToExtended(current_matrix);
                current_rep = EXT_ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Adjacency Matrix -> Extended Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 7: {
                current_map = matrixToMap(current_matrix);
                current_rep = ADJ_MAP;
                cout << "\nDa chuyen doi thanh cong: Adjacency Matrix -> Adjacency Map\n";
                displayCurrentRepresentation();
                break;
            }
            case 8: {
                current_list = extendedToList(current_extended);
                current_rep = ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 9: {
                current_matrix = extendedToMatrix(current_extended);
                current_rep = ADJ_MATRIX;
                cout << "\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency Matrix\n";
                displayCurrentRepresentation();
                break;
            }
            case 10: {
                current_map = extendedToMap(current_extended);
                current_rep = ADJ_MAP;
                cout << "\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency Map\n";
                displayCurrentRepresentation();
                break;
            }
            case 11: {
                current_list = mapToList(current_map);
                current_rep = ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Adjacency Map -> Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 12: {
                current_matrix = mapToMatrix(current_map);
                current_rep = ADJ_MATRIX;
                cout << "\nDa chuyen doi thanh cong: Adjacency Map -> Adjacency Matrix\n";
                displayCurrentRepresentation();
                break;
            }
            case 13: {
                current_extended = mapToExtended(current_map);
                current_rep = EXT_ADJ_LIST;
                cout << "\nDa chuyen doi thanh cong: Adjacency Map -> Extended Adjacency List\n";
                displayCurrentRepresentation();
                break;
            }
            case 14:
                cout << "Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
