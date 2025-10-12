#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000010;

class SegTree {
public:
    int n;
    vector<int> tree, lazy;
    SegTree(int _n) : n(_n), tree(4 * _n, INF), lazy(4 * _n, INF) {}
    void push(int node, int start, int end) {
        if (lazy[node] != INF) {
            tree[node] = min(tree[node], lazy[node]);
            if (start != end) {
                lazy[2 * node] = min(lazy[2 * node], lazy[node]);
                lazy[2 * node + 1] = min(lazy[2 * node + 1], lazy[node]);
            }
            lazy[node] = INF;
        }
    }
    void update_range(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] = val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int l, int r, int val) {
        update_range(1, 0, n - 1, l, r, val);
    }
    int query(int node, int start, int end, int pos) {
        push(node, start, end);
        if (start == end) return tree[node];
        int mid = (start + end) / 2;
        if (pos <= mid)
            return query(2 * node, start, mid, pos);
        else
            return query(2 * node + 1, mid + 1, end, pos);
    }
    int get(int pos) { return query(1, 0, n - 1, pos); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int orig_n, orig_m;
        cin >> orig_n >> orig_m;
        vector<string> orig_grid(orig_n);
        for (auto& s : orig_grid) cin >> s;
        bool transposed = (orig_n > orig_m);
        int rows = transposed ? orig_m : orig_n;
        int cols_num = transposed ? orig_n : orig_m;
        vector<string> g(rows, string(cols_num, '0'));
        if (transposed) {
            for (int i = 0; i < orig_n; ++i) {
                for (int j = 0; j < orig_m; ++j) {
                    g[j][i] = orig_grid[i][j];
                }
            }
        } else {
            g = orig_grid;
        }
        int n = rows, m = cols_num;
        vector<SegTree> segs(m, SegTree(n));
        for (int u = 0; u < n; ++u) {
            for (int d = u + 1; d < n; ++d) {
                int h = d - u + 1;
                vector<int> cols;
                for (int c = 0; c < m; ++c) {
                    if (g[u][c] == '1' && g[d][c] == '1') cols.push_back(c);
                }
                if (cols.size() < 2) continue;
                vector<int> min_w(m, INF);
                for (size_t k = 0; k + 1 < cols.size(); ++k) {
                    int lc = cols[k], rc = cols[k + 1];
                    int ww = rc - lc + 1;
                    for (int jj = lc; jj <= rc; ++jj) {
                        min_w[jj] = min(min_w[jj], ww);
                    }
                }
                for (int j = 0; j < m; ++j) {
                    if (min_w[j] < INF) {
                        long long vv = (long long) h * min_w[j];
                        if (vv < INF) {
                            segs[j].update(u, d, vv);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans_grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = segs[j].get(i);
                ans_grid[i][j] = (val == INF ? 0 : val);
            }
        }
        if (!transposed) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << ans_grid[i][j];
                    if (j < m - 1) cout << " ";
                }
                cout << "\n";
            }
        } else {
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