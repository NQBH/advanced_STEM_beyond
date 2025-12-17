#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

template <class T> struct Matrix {
	vector<vector<T>> v;
	void init(int n, int m) { v = vector<vector<T>>(n, vector<T>(m)); }

	Matrix operator* (Matrix b) {
		int x = v.size(), y = v[0].size(), z = b.v[0].size();
		assert(y == size(b.v));
		Matrix<T> ret;
		ret.init(x, z);
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				for (int k = 0; k < z; ++k) {
					ret.v[i][k] += v[i][j] * b.v[j][k];
					ret.v[i][k] %= MOD;
				}
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    --k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Matrix<ll> A, B;
	A.init(n, n);
	B.init(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) A.v[i][j] = 1;
	Matrix<ll> ret;
	ret.init(n, n);
	for (int i = 0; i < n; ++i) ret.v[i][i] = 1;
	for (ll b = k; b > 0; b >>= 1) {
		if (b & 1) ret = ret * A;
		A = A * A;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ans += ret.v[i][j];
			ans %= MOD;
		}
	cout << ans << '\n';
}