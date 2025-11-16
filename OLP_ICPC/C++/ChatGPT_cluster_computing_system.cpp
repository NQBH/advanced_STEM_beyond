#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    int w;
    Edge(int _u = 0, int _v = 0, int _w = 0): u(_u), v(_v), w(_w) {}
    bool operator<(Edge const& o) const { return w < o.w; }
};

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        p.resize(n);
        r.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<Edge> edges;
    edges.reserve((size_t)n * 20); // heuristic reserve

    // prev_gcds holds pairs (gcd_value, leftmost_index) for subarrays ending at previous j-1
    vector<pair<int, int>> prev;
    for (int j = 0; j < n; j++) {
        vector<pair<int, int>> cur;
        // start new subarray just p[j] alone
        cur.emplace_back(p[j], j);
        // extend all prev subarrays by p[j]
        for (auto &pr : prev) {
            int g = std::gcd(pr.first, p[j]);
            if (cur.back().first == g) {
                // extend leftmost to earlier index
                cur.back().second = pr.second;
            } else {
                cur.emplace_back(g, pr.second);
            }
        }
        // for each distinct gcd g for subarray [l..j], add edge (l, j, g)
        for (auto &pr : cur) {
            int g = pr.first;
            int l = pr.second;
            if (l < j) { // only add if length >=2 (u<v)
                edges.emplace_back(l, j, g);
            }
        }
        prev.swap(cur);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll ans = 0;
    int comps = n;
    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += (ll)e.w;
            if (--comps == 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}
// WA test 1 CF