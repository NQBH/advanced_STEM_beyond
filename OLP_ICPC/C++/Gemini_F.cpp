#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, w, id;
};

// Comparator for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

// Disjoint Set Union (DSU) to check connectivity
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Global variables for HLD and Segment Tree
const int INF = 2e9 + 7;
vector<int> tree_max; // Segment tree array
vector<vector<pair<int, int>>> adj; // Adjacency list for MST
vector<int> parent, depth, heavy, head, pos, sz; // HLD arrays
vector<int> node_weight; // Maps HLD position to edge weight (to parent)
int cur_pos;

// Build the Segment Tree
void build(const vector<int>& weights, int node, int start, int end) {
    if (start == end) {
        tree_max[node] = weights[start];
    } else {
        int mid = (start + end) / 2;
        build(weights, 2 * node, start, mid);
        build(weights, 2 * node + 1, mid + 1, end);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }
}

// Query range [l, r] in Segment Tree
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return -1; // Return -1 (or sufficiently small) for out of bounds
    }
    if (l <= start && end <= r) {
        return tree_max[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(p1, p2);
}

// DFS to calculate subtree sizes and find heavy edges
int dfs_sz(int v, int p, int d) {
    sz[v] = 1;
    parent[v] = p;
    depth[v] = d;
    int max_sz = 0;
    for (auto& edge : adj[v]) {
        int c = edge.first;
        if (c != p) {
            int c_sz = dfs_sz(c, v, d + 1);
            sz[v] += c_sz;
            if (c_sz > max_sz) {
                max_sz = c_sz;
                heavy[v] = c;
            }
        }
    }
    return sz[v];
}

// DFS to decompose the tree and assign positions
void dfs_hld(int v, int h, int w_to_p) {
    head[v] = h;
    pos[v] = ++cur_pos;
    node_weight[cur_pos] = w_to_p; 
    
    if (heavy[v] != -1) {
        int w_heavy = -1;
        for(auto& edge : adj[v]) if(edge.first == heavy[v]) w_heavy = edge.second;
        dfs_hld(heavy[v], h, w_heavy);
    }
    
    for (auto& edge : adj[v]) {
        int c = edge.first;
        int w = edge.second;
        if (c != parent[v] && c != heavy[v]) {
            dfs_hld(c, c, w);
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    // Step 1: Sort edges to consider smallest ones first
    sort(edges.begin(), edges.end(), compareEdges);

    long long mst_sum = 0;
    DSU dsu(n);
    
    // Step 2: Check if smallest n-1 edges form a tree
    for (int i = 0; i < n - 1; ++i) {
        dsu.unite(edges[i].u, edges[i].v);
        mst_sum += edges[i].w;
    }
    
    int components = 0;
    for(int i = 1; i <= n; ++i) if(dsu.parent[i] == i) components++;
    
    // If not a tree (disconnected), the smallest n-1 edges are already the answer
    if (components > 1) {
        cout << mst_sum << "\n";
        return;
    }

    // Step 3: It is a tree. Build MST adjacency list for HLD
    adj.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; ++i) {
        adj[edges[i].u].push_back({edges[i].v, edges[i].w});
        adj[edges[i].v].push_back({edges[i].u, edges[i].w});
    }

    // Initialize HLD structures
    parent.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    heavy.assign(n + 1, -1);
    head.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    node_weight.assign(n + 1, 0);
    cur_pos = 0;

    dfs_sz(1, 0, 0);
    dfs_hld(1, 1, -1); 

    // Build Segment Tree with edge weights
    // Note: Position 1 is root, which has no parent edge, so we mark it invalid (-1)
    tree_max.assign(4 * n + 1, -1);
    node_weight[pos[1]] = -1; 
    build(node_weight, 1, 1, n);

    long long min_total = -1;

    // Step 4: Iterate through all edges NOT in the MST
    for (int i = n - 1; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // Collect intervals covering the path u-v in the HLD structure
        vector<pair<int, int>> path_intervals;
        int a = u, b = v;
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]]) swap(a, b);
            path_intervals.push_back({pos[head[b]], pos[b]});
            b = parent[head[b]];
        }
        if (depth[a] > depth[b]) swap(a, b);
        // a is now LCA. Edge to a (pos[a]) is NOT on the path between descendants
        if (pos[a] + 1 <= pos[b]) {
            path_intervals.push_back({pos[a] + 1, pos[b]});
        }

        sort(path_intervals.begin(), path_intervals.end());

        // Find the maximum weight edge NOT in the path intervals
        // We look for gaps in [2, n]
        int max_outside = -1;
        int curr = 2; // Start from 2 (ignoring root pos 1)
        
        for (auto& p : path_intervals) {
            if (curr < p.first) {
                max_outside = max(max_outside, query(1, 1, n, curr, p.first - 1));
            }
            curr = max(curr, p.second + 1);
        }
        if (curr <= n) {
            max_outside = max(max_outside, query(1, 1, n, curr, n));
        }

        // If a valid swap exists
        if (max_outside != -1) {
            long long new_sum = mst_sum - max_outside + w;
            if (min_total == -1 || new_sum < min_total) {
                min_total = new_sum;
            }
        }
    }

    cout << min_total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}