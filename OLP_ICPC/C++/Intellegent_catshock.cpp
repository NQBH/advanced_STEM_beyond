#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uid(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

ll uld(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(rng);
}

const int N = 2e5 + 10;
vector<vector<int>> pfac(N + 1); // pre-calculated prime divisors with Sieve of Eratosthenes

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> dep(n), par(n), ch(n);
	auto dfs = [&](auto self, int c, int p) -> void {
		if (p != -1) dep[c] = dep[p] + 1;
		par[c] = p;
		for (int x : g[c]) {
			if (x == p) continue;
			self(self, x, c);
			++ch[c];
		}
	};
	dfs(dfs, n - 1, -1);
	array<vector<int>, 2> leaves;
	leaves[0];

	for (int i = 0; i < n; ++i)
		if (ch[i] == 0) leaves[dep[i] & 1].push_back(i);

	vector<array<int, 2>> ans;
	int col = dep[0] & 1;
	for (int i = 0; i < n - 1; ++i) {
		if (leaves[col ^ 1].empty()) {
			ans.push_back({1, -1});
			col ^= 1;
		}
		int nxt = leaves[col ^ 1].back();
		leaves[col ^ 1].pop_back();
		ans.push_back({2, nxt});

		int p = par[nxt];
		--ch[p];
		if (ch[p] == 0) leaves[dep[p] & 1].push_back(p);
		ans.push_back({1, -1});
		col ^= 1;
	}
	cout << ans.size() << '\n';
	for (auto [x, y] : ans)
		if (x == 1) cout << "1\n";
		else cout << "2 " << y + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}