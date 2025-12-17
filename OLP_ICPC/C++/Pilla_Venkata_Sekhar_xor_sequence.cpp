#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

vector<vector<ll>> mat_mul(vector<vector<ll>> mat1, vector<vector<ll>> mat2, int sz) {
	vector<vector<ll>> mul(sz, vector<ll>(sz, 0));
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			for (int k = 0; k < sz; ++k) {
				mul[i][j] += mat1[i][k] * mat2[k][j];
				mul[i][j] %= MOD;
			}
	return mul;
}

int mat_expo(vector<vector<ll>> p, int sz, ll pow) {
	vector<vector<ll>> ans(sz, vector<ll>(sz, 0));
	for (int i = 0; i < sz; ++i) ans[i][i] = 1;
	if (!pow) return sz;
	else {
		while (pow) {
			if (pow & 1) ans = mat_mul(ans, p, sz);
			p = mat_mul(p, p, sz);
			pow >>= 1;
		}
	}
	ll cnt = 0;
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			if (ans[i][j]) {
				cnt += ans[i][j];
				cnt %= MOD;
			}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll k, a[n];
    cin >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> mat(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ll cnt = 0, x = a[i] ^ a[j];
			while (x) {
				if (x & 1) ++cnt;
				x >>= 1;
			}
			if (cnt % 3 == 0) mat[i][j] = 1, mat[j][i] = 1;
		}
	cout << mat_expo(mat, n, k - 1);
}