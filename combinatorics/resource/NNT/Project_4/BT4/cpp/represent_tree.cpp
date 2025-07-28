#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm> // For std::sort, std::min, std::max
#include <map> // For temporary use in conversions to handle canonical edges

using namespace std;

// Tree representations
struct ParentArray {
    vector<int> parents; // parents[v] = parent of v, -1 if root
    int n;
    int root_node; // Store the root node
};

struct FCNS {
    vector<int> first_child; // first_child[v] = first child of v, -1 if leaf
    vector<int> next_sibling; // next_sibling[v] = next sibling of v, -1 if last sibling
    int n;
};

// Graph-based representation of trees (using Extended Adjacency List, undirected edges)
// For trees, edges are implicitly directed from parent to child. However, this EAL
// treats them as undirected connections for consistency with previous graph context.
// When converting back to a tree-specific representation, the root_node is used
// to re-establish parent-child relationships via traversal.
struct TreeExtendedAdjacencyList {
    vector<pair<int, int>> edges; // Stores (u, v) for each edge, where u is parent of v OR v is parent of u
    vector<vector<int>> incoming; // indices to edges
    vector<vector<int>> outgoing; // indices to edges
    int n;
    int m; // number of edges
};

// Internal representation for easier conversions between tree structures
// This stores children for each node, which is convenient for building other representations.
struct TreeChildrenList {
    vector<vector<int>> children; // children[u] = list of children of u
    int n;
    int root_node; // The root of the tree
};

// Enum for current representation
enum TreeRepresentation {
    PARENT_ARRAY,
    FCNS_REP,
    TREE_EAL
};

// Global variables to track current state
ParentArray current_parent_array;
FCNS current_fcns;
TreeExtendedAdjacencyList current_tree_eal;
TreeChildrenList current_children_list_internal; // Used internally for conversions, always kept consistent

TreeRepresentation current_tree_rep; // Initialized after input parsing

// Helper function to get representation name as a string
string getTreeRepName(TreeRepresentation rep) {
    switch (rep) {
        case PARENT_ARRAY: return "Array of Parents";
        case FCNS_REP: return "First-Child Next-Sibling";
        case TREE_EAL: return "Graph-based (Extended Adjacency List)";
        default: return "Unknown";
    }
}

// ========== CONVERSION FUNCTIONS ==========

// Converts a TreeChildrenList to a ParentArray.
// Iterates through children lists to determine each node's parent.
ParentArray childrenListToParentArray(const TreeChildrenList& cl) {
    ParentArray pa;
    pa.n = cl.n;
    pa.parents.assign(cl.n, -1); // Initialize all parents to -1 (indicating no parent yet, or root)
    pa.root_node = cl.root_node;

    for (int u = 0; u < cl.n; ++u) {
        for (int v : cl.children[u]) {
            pa.parents[v] = u; // u is the parent of v
        }
    }
    return pa;
}

// Converts a ParentArray to a TreeChildrenList.
// Iterates through the parent array to build children lists.
TreeChildrenList parentArrayToChildrenList(const ParentArray& pa) {
    TreeChildrenList cl;
    cl.n = pa.n;
    cl.children.resize(cl.n);
    cl.root_node = pa.root_node;

    for (int v = 0; v < pa.n; ++v) {
        if (pa.parents[v] != -1) { // If v has a parent
            cl.children[pa.parents[v]].push_back(v); // Add v to its parent's children list
        }
    }
    // Sort children lists for consistent FCNS conversion later.
    for (int i = 0; i < cl.n; ++i) {
        sort(cl.children[i].begin(), cl.children[i].end());
    }
    return cl;
}

// Converts a TreeChildrenList to a First-Child Next-Sibling (FCNS) representation.
// Assumes children lists are sorted for consistent FCNS output.
FCNS childrenListToFCNS(const TreeChildrenList& cl) {
    FCNS fcns;
    fcns.n = cl.n;
    fcns.first_child.assign(cl.n, -1); // Initialize all to -1
    fcns.next_sibling.assign(cl.n, -1); // Initialize all to -1

    for (int u = 0; u < cl.n; ++u) {
        if (!cl.children[u].empty()) {
            // The first child of u is the first element in its sorted children list
            fcns.first_child[u] = cl.children[u][0];
            // For other children, set next_sibling pointers
            for (size_t i = 0; i < cl.children[u].size() - 1; ++i) {
                fcns.next_sibling[cl.children[u][i]] = cl.children[u][i+1];
            }
        }
    }
    return fcns;
}

// Converts a First-Child Next-Sibling (FCNS) representation to a TreeChildrenList.
// Requires the root_node to start the traversal and reconstruct the tree structure.
TreeChildrenList fcnstToChildrenList(const FCNS& fcns, int root_node) {
    TreeChildrenList cl;
    cl.n = fcns.n;
    cl.children.resize(cl.n);
    cl.root_node = root_node;

    // Use a queue for BFS to traverse the tree and build the children list
    queue<int> q;
    q.push(root_node);
    vector<bool> visited(fcns.n, false);
    visited[root_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int current_child = fcns.first_child[u];
        while (current_child != -1) {
            if (!visited[current_child]) {
                cl.children[u].push_back(current_child); // u is parent of current_child
                visited[current_child] = true;
                q.push(current_child);
            }
            current_child = fcns.next_sibling[current_child]; // Move to the next sibling
        }
    }
    // Sort children lists for consistency.
    for (int i = 0; i < cl.n; ++i) {
        sort(cl.children[i].begin(), cl.children[i].end());
    }
    return cl;
}

// Converts a TreeChildrenList to a TreeExtendedAdjacencyList (graph-based).
// Each parent-child relationship becomes an edge in the EAL.
// The EAL is treated as undirected for tree edges (u,v) and (v,u) point to the same edge index.
TreeExtendedAdjacencyList childrenListToTreeEAL(const TreeChildrenList& cl) {
    TreeExtendedAdjacencyList teal;
    teal.n = cl.n;
    teal.incoming.resize(cl.n);
    teal.outgoing.resize(cl.n);
    teal.m = 0;

    for (int u = 0; u < cl.n; ++u) {
        for (int v : cl.children[u]) {
            teal.edges.push_back({u, v}); // Store the edge as (parent, child)
            int edge_idx = teal.edges.size() - 1;

            teal.outgoing[u].push_back(edge_idx); // u has an outgoing edge to v
            teal.incoming[v].push_back(edge_idx); // v has an incoming edge from u

            // For undirected graph representation of tree edges (as per previous context):
            teal.outgoing[v].push_back(edge_idx); // v also has an "outgoing" connection to u
            teal.incoming[u].push_back(edge_idx); // u also has an "incoming" connection from v
            teal.m++; // Increment total edge count
        }
    }
    return teal;
}

// Converts a TreeExtendedAdjacencyList (graph-based) back to a TreeChildrenList.
// Requires the root_node to start a BFS traversal to correctly identify parent-child relationships.
TreeChildrenList treeEALToChildrenList(const TreeExtendedAdjacencyList& teal, int root_node) {
    TreeChildrenList cl;
    cl.n = teal.n;
    cl.children.resize(cl.n);
    cl.root_node = root_node;

    if (cl.n == 0) return cl;

    // Build a temporary adjacency list from EAL for BFS traversal.
    // This handles the undirected nature of TreeExtendedAdjacencyList by creating
    // a simple adjacency list where each node points to its direct neighbors.
    vector<vector<int>> temp_adj(teal.n);
    for (const auto& edge_pair : teal.edges) {
        temp_adj[edge_pair.first].push_back(edge_pair.second);
        temp_adj[edge_pair.second].push_back(edge_pair.first); // Undirected connection
    }

    queue<int> q;
    q.push(root_node);
    vector<bool> visited(cl.n, false);
    visited[root_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : temp_adj[u]) {
            if (!visited[v]) {
                cl.children[u].push_back(v); // If v is not visited, u must be its parent
                visited[v] = true;
                q.push(v);
            }
        }
    }
    // Sort children lists for consistency.
    for (int i = 0; i < cl.n; ++i) {
        sort(cl.children[i].begin(), cl.children[i].end());
    }
    return cl;
}

// ========== DISPLAY FUNCTIONS ==========

// Displays the Array of Parents representation.
void displayParentArray(const ParentArray& pa) {
    cout << "Array of Parents:\n";
    cout << "Root: " << pa.root_node << "\n";
    for (int i = 0; i < pa.n; ++i) {
        cout << "Parent[" << i << "] = " << pa.parents[i] << "\n";
    }
}

// Displays the First-Child Next-Sibling representation.
void displayFCNS(const FCNS& fcns) {
    cout << "First-Child Next-Sibling Representation:\n";
    for (int i = 0; i < fcns.n; ++i) {
        cout << "Node " << i << ": ";
        cout << "First Child = " << fcns.first_child[i];
        cout << ", Next Sibling = " << fcns.next_sibling[i] << "\n";
    }
}

// Displays the Graph-based representation (TreeExtendedAdjacencyList).
void displayTreeEAL(const TreeExtendedAdjacencyList& teal) {
    cout << "Graph-based Representation (Extended Adjacency List):\n";
    cout << "Total Edges (m): " << teal.m << "\n";
    cout << "Edges (u,v) and their indices:\n";
    for (int i = 0; i < teal.edges.size(); ++i) {
        cout << "  Edge " << i << ": (" << teal.edges[i].first << "," << teal.edges[i].second << ")\n";
    }

    cout << "Outgoing edges (indices):\n";
    for (int i = 0; i < teal.n; ++i) {
        cout << i << ": ";
        for (int edge_idx : teal.outgoing[i]) {
            cout << edge_idx << " ";
        }
        cout << "\n";
    }

    cout << "Incoming edges (indices):\n";
    for (int i = 0; i < teal.n; ++i) {
        cout << i << ": ";
        for (int edge_idx : teal.incoming[i]) {
            cout << edge_idx << " ";
        }
        cout << "\n";
    }
}

// Function to display the current tree representation based on global state.
void displayCurrentTreeRepresentation() {
    cout << "\n=== CAY HIEN TAI ===";
    switch (current_tree_rep) {
        case PARENT_ARRAY:
            cout << " (Array of Parents)\n";
            displayParentArray(current_parent_array);
            break;
        case FCNS_REP:
            cout << " (First-Child Next-Sibling)\n";
            displayFCNS(current_fcns);
            break;
        case TREE_EAL:
            cout << " (Graph-based (Extended Adjacency List))\n";
            displayTreeEAL(current_tree_eal);
            break;
    }
    cout << "\n";
}

// Function to validate if the chosen conversion is valid from the current representation.
bool isValidTreeConversion(int choice) {
    switch (choice) {
        case 1: // Display current
            return true;
        case 2: // PA -> FCNS
            return current_tree_rep == PARENT_ARRAY;
        case 3: // PA -> EAL
            return current_tree_rep == PARENT_ARRAY;
        case 4: // FCNS -> PA
            return current_tree_rep == FCNS_REP;
        case 5: // FCNS -> EAL
            return current_tree_rep == FCNS_REP;
        case 6: // EAL -> PA
            return current_tree_rep == TREE_EAL;
        case 7: // EAL -> FCNS
            return current_tree_rep == TREE_EAL;
        case 8: // Exit
            return true;
        default:
            return false;
    }
}

int main() {
    cout << "=== CHUONG TRINH CHUYEN DOI BIEU DIEN CAY ===\n\n";

    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    current_children_list_internal.n = n;
    current_children_list_internal.children.resize(n);

    vector<int> in_degree(n, 0); // Used to find the root (node with in-degree 0)

    cout << "Nhap danh sach con cho tung dinh (vd: <so_con> <con_1> <con_2> ...):\n";
    cout << "Luu y: Dinh con phai nam trong khoang [0, n-1].\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i << ": ";
        int num_children;
        cin >> num_children;
        for (int k = 0; k < num_children; ++k) {
            int child_node;
            cin >> child_node;
            if (child_node < 0 || child_node >= n) {
                cout << "Loi: Dinh con " << child_node << " khong hop le. Vui long nhap lai dinh con nay.\n";
                k--; // Decrement k to re-read this child
                continue;
            }
            if (child_node == i) { // Trees do not allow self-loops
                cout << "Loi: Cay khong co khuyen. Dinh con khong the la chinh no. Vui long nhap lai dinh con nay.\n";
                k--;
                continue;
            }
            current_children_list_internal.children[i].push_back(child_node);
            in_degree[child_node]++;
        }
        // Sort children for consistent FCNS conversion later.
        // This is crucial because FCNS relies on a defined order of siblings.
        sort(current_children_list_internal.children[i].begin(), current_children_list_internal.children[i].end());
    }

    // Find the root of the tree
    int root = -1;
    int root_count = 0;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            root = i;
            root_count++;
        }
    }
    
    // Validate if the input forms a valid tree (exactly one root for n > 0)
    if (n > 0 && root_count != 1) {
        cout << "Loi: Do thi khong phai la cay (phai co dung mot goc).\n";
        return 1; // Exit if not a valid tree
    }
    current_children_list_internal.root_node = root;

    // Initialize current_parent_array from the initial children list
    current_parent_array = childrenListToParentArray(current_children_list_internal);
    current_tree_rep = PARENT_ARRAY; // Set initial representation to Array of Parents

    while (true) {
        cout << "\n=== MENU CHUYEN DOI CAY ===\n";
        cout << "1. Hien thi cay hien tai\n";
        cout << "=== CHUYEN DOI TU ARRAY OF PARENTS ===\n";
        cout << "2. Array of Parents -> First-Child Next-Sibling\n";
        cout << "3. Array of Parents -> Graph-based (Extended Adjacency List)\n";
        cout << "\n=== CHUYEN DOI TU FIRST-CHILD NEXT-SIBLING ===\n";
        cout << "4. First-Child Next-Sibling -> Array of Parents\n";
        cout << "5. First-Child Next-Sibling -> Graph-based (Extended Adjacency List)\n";
        cout << "\n=== CHUYEN DOI TU GRAPH-BASED (EXTENDED ADJACENCY LIST) ===\n";
        cout << "6. Graph-based (Extended Adjacency List) -> Array of Parents\n";
        cout << "7. Graph-based (Extended Adjacency List) -> First-Child Next-Sibling\n";
        cout << "\n8. Thoat\n";
        cout << "Chon: ";

        int choice;
        cin >> choice;

        // Validate user's choice based on current representation
        if (!isValidTreeConversion(choice)) {
            cout << "\nLOI: Khong the chuyen doi! Cay hien tai dang o dang "
                 << getTreeRepName(current_tree_rep) << " nhung ban chon chuyen doi tu dang khac.\n";
            cout << "Vui long chon lai!\n";
            continue;
        }

        // Perform the chosen conversion
        switch (choice) {
            case 1:
                displayCurrentTreeRepresentation();
                break;
            case 2: { // PA -> FCNS
                // Convert PA to ChildrenList (internal) then to FCNS
                current_children_list_internal = parentArrayToChildrenList(current_parent_array);
                current_fcns = childrenListToFCNS(current_children_list_internal);
                current_tree_rep = FCNS_REP;
                cout << "\nDa chuyen doi thanh cong: Array of Parents -> First-Child Next-Sibling\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 3: { // PA -> EAL
                // Convert PA to ChildrenList (internal) then to EAL
                current_children_list_internal = parentArrayToChildrenList(current_parent_array);
                current_tree_eal = childrenListToTreeEAL(current_children_list_internal);
                current_tree_rep = TREE_EAL;
                cout << "\nDa chuyen doi thanh cong: Array of Parents -> Graph-based (Extended Adjacency List)\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 4: { // FCNS -> PA
                // Convert FCNS to ChildrenList (internal) then to PA
                current_children_list_internal = fcnstToChildrenList(current_fcns, current_children_list_internal.root_node);
                current_parent_array = childrenListToParentArray(current_children_list_internal);
                current_tree_rep = PARENT_ARRAY;
                cout << "\nDa chuyen doi thanh cong: First-Child Next-Sibling -> Array of Parents\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 5: { // FCNS -> EAL
                // Convert FCNS to ChildrenList (internal) then to EAL
                current_children_list_internal = fcnstToChildrenList(current_fcns, current_children_list_internal.root_node);
                current_tree_eal = childrenListToTreeEAL(current_children_list_internal);
                current_tree_rep = TREE_EAL;
                cout << "\nDa chuyen doi thanh cong: First-Child Next-Sibling -> Graph-based (Extended Adjacency List)\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 6: { // EAL -> PA
                // Convert EAL to ChildrenList (internal) then to PA
                current_children_list_internal = treeEALToChildrenList(current_tree_eal, current_children_list_internal.root_node);
                current_parent_array = childrenListToParentArray(current_children_list_internal);
                current_tree_rep = PARENT_ARRAY;
                cout << "\nDa chuyen doi thanh cong: Graph-based (Extended Adjacency List) -> Array of Parents\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 7: { // EAL -> FCNS
                // Convert EAL to ChildrenList (internal) then to FCNS
                current_children_list_internal = treeEALToChildrenList(current_tree_eal, current_children_list_internal.root_node);
                current_fcns = childrenListToFCNS(current_children_list_internal);
                current_tree_rep = FCNS_REP;
                cout << "\nDa chuyen doi thanh cong: Graph-based (Extended Adjacency List) -> First-Child Next-Sibling\n";
                displayCurrentTreeRepresentation();
                break;
            }
            case 8:
                cout << "Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
