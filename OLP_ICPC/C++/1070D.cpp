#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

struct edge {
	int u, v;
	ll valu, valv;
};

bool cf_edge(const edge& a, const edge& b) {
	return a.valv < b.valv;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		vector<edge> edges;
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v, a[u], a[v]});
		}
		sort(edges.begin(), edges.end(), cf_edge);
		vector<map<int, ll>> sumdp(n + 1);
		ll ans = 0;
		for (const auto& e : edges) {
			int u = e.u, v = e.v;
			ll valu = e.valu, valv = e.valv;
			ll curr_path = 1; // base case: path consisting of just edge (u,v) is valid
			ll require_val = valv - valu; // if < 0, then not exist t s.t. a[t] = a[v] - a[u]
			if (require_val > 0) {
				auto it = sumdp[u].find(require_val);
				if (it != sumdp[u].end()) curr_path = (curr_path + it->second) % mod;
			}
			ans = (ans + curr_path) % mod;
			sumdp[v][valu] = (sumdp[v][valu] + curr_path) % mod;
		}
		cout << ans << '\n';
	}
}