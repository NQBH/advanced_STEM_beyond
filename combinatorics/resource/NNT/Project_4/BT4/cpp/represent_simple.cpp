#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

// Graph representations
struct AdjacencyMatrix {
    vector<vector<bool>> matrix;
    int n;
};

struct AdjacencyList {
    vector<vector<int>> adj;
    int n;
};

struct ExtendedAdjacencyList {
    vector<vector<int>> incoming;
    vector<vector<int>> outgoing;
    vector<pair<int, int>> edges;
    int n, m;
};

struct AdjacencyMap {
    unordered_map<int, unordered_map<int, pair<int, int>>> incoming;
    unordered_map<int, unordered_map<int, pair<int, int>>> outgoing;
    int n, m;
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

// ========== ALL 12 CONVERSION FUNCTIONS ==========

// 1. Adjacency List ↔ Adjacency Matrix
AdjacencyMatrix listToMatrix(const AdjacencyList& list) {
    AdjacencyMatrix matrix;
    matrix.n = list.n;
    matrix.matrix.resize(matrix.n, vector<bool>(matrix.n, false));
    
    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            matrix.matrix[i][j] = true;
        }
    }
    return matrix;
}

AdjacencyList matrixToList(const AdjacencyMatrix& matrix) {
    AdjacencyList list;
    list.n = matrix.n;
    list.adj.resize(list.n);
    
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.matrix[i][j]) {
                list.adj[i].push_back(j);
            }
        }
    }
    return list;
}

// 2. Adjacency Matrix ↔ Extended Adjacency List
ExtendedAdjacencyList matrixToExtended(const AdjacencyMatrix& matrix) {
    ExtendedAdjacencyList ext;
    ext.n = matrix.n;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    
    // Collect all edges
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.matrix[i][j] && i <= j) { // Avoid duplicate edges
                ext.edges.push_back({i, j});
            }
        }
    }
    ext.m = ext.edges.size();
    
    // Build incoming and outgoing lists
    for (int i = 0; i < ext.edges.size(); i++) {
        int u = ext.edges[i].first;
        int v = ext.edges[i].second;
        
        ext.outgoing[u].push_back(i);
        ext.incoming[v].push_back(i);
        
        if (u != v) { // If not self-loop
            ext.outgoing[v].push_back(i);
            ext.incoming[u].push_back(i);
        }
    }
    
    return ext;
}

AdjacencyMatrix extendedToMatrix(const ExtendedAdjacencyList& ext) {
    AdjacencyMatrix matrix;
    matrix.n = ext.n;
    matrix.matrix.resize(matrix.n, vector<bool>(matrix.n, false));
    
    for (auto& edge : ext.edges) {
        int u = edge.first;
        int v = edge.second;
        matrix.matrix[u][v] = true;
        matrix.matrix[v][u] = true; // Undirected graph
    }
    
    return matrix;
}

// 3. Adjacency Matrix ↔ Adjacency Map
AdjacencyMap matrixToMap(const AdjacencyMatrix& matrix) {
    AdjacencyMap map;
    map.n = matrix.n;
    
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.matrix[i][j] && i <= j) { // Avoid duplicate edges
                map.outgoing[i][j] = {i, j};
                map.incoming[j][i] = {i, j};
                
                if (i != j) {
                    map.outgoing[j][i] = {i, j};
                    map.incoming[i][j] = {i, j};
                }
            }
        }
    }
    
    // Count edges
    map.m = 0;
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.matrix[i][j] && i <= j) map.m++;
        }
    }
    
    return map;
}

AdjacencyMatrix mapToMatrix(const AdjacencyMap& map) {
    AdjacencyMatrix matrix;
    matrix.n = map.n;
    matrix.matrix.resize(matrix.n, vector<bool>(matrix.n, false));
    
    for (auto& vertex : map.outgoing) {
        int u = vertex.first;
        for (auto& edge : vertex.second) {
            int v = edge.first;
            matrix.matrix[u][v] = true;
            matrix.matrix[v][u] = true; // Undirected graph
        }
    }
    
    return matrix;
}

// 4. Adjacency List ↔ Extended Adjacency List
ExtendedAdjacencyList listToExtended(const AdjacencyList& list) {
    ExtendedAdjacencyList ext;
    ext.n = list.n;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    
    // Collect all edges
    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            if (i <= j) { // Avoid duplicate edges for undirected graph
                ext.edges.push_back({i, j});
            }
        }
    }
    ext.m = ext.edges.size();
    
    // Build incoming and outgoing lists
    for (int i = 0; i < ext.edges.size(); i++) {
        int u = ext.edges[i].first;
        int v = ext.edges[i].second;
        
        ext.outgoing[u].push_back(i);
        ext.incoming[v].push_back(i);
        
        if (u != v) { // If not self-loop
            ext.outgoing[v].push_back(i);
            ext.incoming[u].push_back(i);
        }
    }
    
    return ext;
}

AdjacencyList extendedToList(const ExtendedAdjacencyList& ext) {
    AdjacencyList list;
    list.n = ext.n;
    list.adj.resize(list.n);
    
    for (auto& edge : ext.edges) {
        int u = edge.first;
        int v = edge.second;
        list.adj[u].push_back(v);
        list.adj[v].push_back(u); // Undirected graph
    }
    
    return list;
}

// 5. Adjacency List ↔ Adjacency Map
AdjacencyMap listToMap(const AdjacencyList& list) {
    AdjacencyMap map;
    map.n = list.n;
    
    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            if (i <= j) { // Avoid duplicate edges for undirected graph
                map.outgoing[i][j] = {i, j};
                map.incoming[j][i] = {i, j};
                
                if (i != j) {
                    map.outgoing[j][i] = {i, j};
                    map.incoming[i][j] = {i, j};
                }
            }
        }
    }
    
    // Count edges
    map.m = 0;
    for (int i = 0; i < list.n; i++) {
        for (int j : list.adj[i]) {
            if (i <= j) map.m++;
        }
    }
    
    return map;
}

AdjacencyList mapToList(const AdjacencyMap& map) {
    AdjacencyList list;
    list.n = map.n;
    list.adj.resize(list.n);
    
    for (auto& vertex : map.outgoing) {
        int u = vertex.first;
        for (auto& edge : vertex.second) {
            int v = edge.first;
            list.adj[u].push_back(v);
        }
    }
    
    return list;
}

// 6. Extended Adjacency List ↔ Adjacency Map
AdjacencyMap extendedToMap(const ExtendedAdjacencyList& ext) {
    AdjacencyMap map;
    map.n = ext.n;
    map.m = ext.m;
    
    for (int i = 0; i < ext.edges.size(); i++) {
        int u = ext.edges[i].first;
        int v = ext.edges[i].second;
        
        map.outgoing[u][v] = {u, v};
        map.incoming[v][u] = {u, v};
        
        if (u != v) {
            map.outgoing[v][u] = {u, v};
            map.incoming[u][v] = {u, v};
        }
    }
    
    return map;
}

ExtendedAdjacencyList mapToExtended(const AdjacencyMap& map) {
    ExtendedAdjacencyList ext;
    ext.n = map.n;
    ext.m = map.m;
    ext.incoming.resize(ext.n);
    ext.outgoing.resize(ext.n);
    
    // Collect unique edges
    set<pair<int, int>> unique_edges;
    for (auto& vertex : map.outgoing) {
        int u = vertex.first;
        for (auto& edge : vertex.second) {
            int v = edge.first;
            if (u <= v) unique_edges.insert({u, v});
        }
    }
    
    ext.edges = vector<pair<int, int>>(unique_edges.begin(), unique_edges.end());
    
    // Build incoming and outgoing lists
    for (int i = 0; i < ext.edges.size(); i++) {
        int u = ext.edges[i].first;
        int v = ext.edges[i].second;
        
        ext.outgoing[u].push_back(i);
        ext.incoming[v].push_back(i);
        
        if (u != v) {
            ext.outgoing[v].push_back(i);
            ext.incoming[u].push_back(i);
        }
    }
    
    return ext;
}

// Display functions
void displayMatrix(const AdjacencyMatrix& matrix) {
    cout << "Adjacency Matrix:\n";
    cout << "  ";
    for (int i = 0; i < matrix.n; i++) {
        cout << i << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < matrix.n; i++) {
        cout << i << " ";
        for (int j = 0; j < matrix.n; j++) {
            cout << (matrix.matrix[i][j] ? "1 " : "0 ");
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
    cout << "Edges: ";
    for (int i = 0; i < ext.edges.size(); i++) {
        cout << "(" << ext.edges[i].first << "," << ext.edges[i].second << ") ";
    }
    cout << "\n";
    
    cout << "Outgoing edges:\n";
    for (int i = 0; i < ext.n; i++) {
        cout << i << ": ";
        for (int edge : ext.outgoing[i]) {
            cout << edge << " ";
        }
        cout << "\n";
    }
    
    cout << "Incoming edges:\n";
    for (int i = 0; i < ext.n; i++) {
        cout << i << ": ";
        for (int edge : ext.incoming[i]) {
            cout << edge << " ";
        }
        cout << "\n";
    }
}

void displayMap(const AdjacencyMap& map) {
    cout << "Adjacency Map:\n";
    cout << "Outgoing mappings:\n";
    for (int i = 0; i < map.n; i++) {
        cout << i << ": ";
        auto it = map.outgoing.find(i);
        if (it != map.outgoing.end()) {
            for (auto& p : it->second) {
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
            for (auto& p : it->second) {
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
    cout << "=== CHUONG TRINH CHUYEN DOI BIEU DIEN DO THI DON ===\n\n";
    
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;
    
    current_list.n = n;
    current_list.adj.resize(n);
    
    cout << "Nhap " << m << " canh (dinh dau dinh cuoi):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
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
