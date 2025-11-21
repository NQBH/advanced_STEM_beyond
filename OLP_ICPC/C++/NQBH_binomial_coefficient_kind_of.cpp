#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1e9 + 7;

ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	vector<int> n(t), k(t);
	for (int &x : n) cin >> x;
	for (int &x : k) cin >> x;
	for (int i = 0; i < t; ++i) cout << binpow(2, k[i], m) << '\n';
}