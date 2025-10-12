#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000010;  // Define a large constant for infinity to represent uninitialized minimum values

// Segment Tree class for range minimum updates and point queries
class SegTree {
public:
    int n;  // Number of leaves in the segment tree
    vector<int> tree, lazy;  // Tree for min values, lazy for pending updates
    SegTree(int _n) : n(_n), tree(4 * _n, INF), lazy(4 * _n, INF) {}  // Constructor: initialize tree and lazy with INF

    // Push down lazy propagation to this node and its children
    void push(int node, int start, int end) {
        if (lazy[node] != INF) {  // If there's a pending update
            tree[node] = min(tree[node], lazy[node]);  // Apply to current node
            if (start != end) {  // If not a leaf, propagate to children
                lazy[2 * node] = min(lazy[2 * node], lazy[node]);
                lazy[2 * node + 1] = min(lazy[2 * node + 1], lazy[node]);
            }
            lazy[node] = INF;  // Clear lazy flag
        }
    }

    // Update range [l, r] with value val (min update)
    void update_range(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);  // Push any pending updates
        if (start > end || start > r || end < l) return;  // Out of range
        if (l <= start && end <= r) {  // Fully covered by update range
            lazy[node] = val;  // Set lazy
            push(node, start, end);  // Apply immediately
            return;
        }
        int mid = (start + end) / 2;  // Split into children
        update_range(2 * node, start, mid, l, r, val);  // Recurse left
        update_range(2 * node + 1, mid + 1, end, l, r, val);  // Recurse right
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);  // Update current min from children
    }

    // Public wrapper for range update
    void update(int l, int r, int val) {
        update_range(1, 0, n - 1, l, r, val);
    }

    // Query the min at position pos (with push down)
    int query(int node, int start, int end, int pos) {
        push(node, start, end);  // Push pending updates
        if (start == end) return tree[node];  // Leaf reached
        int mid = (start + end) / 2;
        if (pos <= mid)
            return query(2 * node, start, mid, pos);  // Go left
        else
            return query(2 * node + 1, mid + 1, end, pos);  // Go right
    }

    // Public wrapper for point query
    int get(int pos) { return query(1, 0, n - 1, pos); }
};

int main() {
    ios::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Untie cin from cout
    int t;
    cin >> t;  // Read number of test cases
    for (int tt = 0; tt < t; ++tt) {  // Loop over test cases
        int orig_n, orig_m;
        cin >> orig_n >> orig_m;  // Read original dimensions
        vector<string> orig_grid(orig_n);
        for (auto& s : orig_grid) cin >> s;  // Read original grid rows

        // Transpose if rows > columns to optimize (since we fix row pairs, better to have fewer rows)
        bool transposed = (orig_n > orig_m);
        int rows = transposed ? orig_m : orig_n;  // Effective rows after possible transpose
        int cols_num = transposed ? orig_n : orig_m;  // Effective columns
        vector<string> g(rows, string(cols_num, '0'));  // Transposed grid if needed
        if (transposed) {
            // Perform transpose: g[j][i] = orig_grid[i][j]
            for (int i = 0; i < orig_n; ++i) {
                for (int j = 0; j < orig_m; ++j) {
                    g[j][i] = orig_grid[i][j];
                }
            }
        } else {
            g = orig_grid;  // No transpose needed
        }
        int n = rows, m = cols_num;  // Set effective n (rows), m (cols)

        // One segment tree per column for efficient row-range min updates/queries
        vector<SegTree> segs(m, SegTree(n));

        // Enumerate all possible top-bottom row pairs for rectangles
        for (int u = 0; u < n; ++u) {
            for (int d = u + 1; d < n; ++d) {  // d > u as per problem (u < d)
                int h = d - u + 1;  // Height of rectangle
                vector<int> cols;  // Columns where both top and bottom are 1 (possible corners)
                for (int c = 0; c < m; ++c) {
                    if (g[u][c] == '1' && g[d][c] == '1') cols.push_back(c);  // Collect corner candidates
                }
                if (cols.size() < 2) continue;  // Need at least two corners for a rectangle

                // For each column j, find min width w such that some l <= j <= r with l,r in cols
                vector<int> min_w(m, INF);
                for (size_t k = 0; k + 1 < cols.size(); ++k) {  // Process consecutive corner pairs
                    int lc = cols[k], rc = cols[k + 1];  // Left and right corner for this segment
                    int ww = rc - lc + 1;  // Width of this segment
                    for (int jj = lc; jj <= rc; ++jj) {  // Update all j in [lc, rc]
                        min_w[jj] = min(min_w[jj], ww);
                    }
                }

                // For each column j with valid min_w, compute area and update segtree for rows [u,d]
                for (int j = 0; j < m; ++j) {
                    if (min_w[j] < INF) {
                        long long vv = (long long) h * min_w[j];  // Area (avoid int overflow)
                        if (vv < INF) {  // If area is reasonable
                            segs[j].update(u, d, vv);  // Update min area for rows u to d in column j
                        }
                    }
                }
            }
        }

        // Build answer grid from segtree queries
        vector<vector<int>> ans_grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = segs[j].get(i);  // Query min area covering row i in col j
                ans_grid[i][j] = (val == INF ? 0 : val);  // 0 if no rectangle covers
            }
        }

        // Output: if transposed, need to transpose back the answer
        if (!transposed) {
            // Direct output
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << ans_grid[i][j];
                    if (j < m - 1) cout << " ";
                }
                cout << "\n";
            }
        } else {
            // Transpose output: ans_grid[j][i] corresponds to original (i,j)
            for (int i = 0; i < orig_n; ++i) {
                for (int j = 0; j < orig_m; ++j) {
                    cout << ans_grid[j][i];
                    if (j < orig_m - 1) cout << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}