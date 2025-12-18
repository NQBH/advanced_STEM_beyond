#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> S(int n, int m) {
	if (!n) return {2 % m, 4 % m}; // base case: S_0 = 2, S_1 = 4
	auto [Sk, Sk1] = S(n >> 1, m); // S_k & S_{k + 1}
	ll S2k = (Sk * Sk - 2) % m, S2k1 = (Sk * Sk1 - 4) % m; // S_{2k} = (S_k)^2 - 2, S_{2k+1} = S_k * S_{k+1} - 4
	if (S2k < 0) S2k += m;
	if (S2k1 < 0) S2k1 += m;
	if (n & 1) { // return {S_{2k+1}, S_{2k+2}}
		ll S2k2 = (4 * S2k1 - S2k) % m;
		if (S2k2 < 0) S2k2 += m;
		return {S2k1, S2k2};
	} else return {S2k, S2k1}; // return {S_{2k}, S_{2k+1}}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	pair<ll, ll> ans = S(n, m);
    	cout << ans.first << '\n';
    }
}