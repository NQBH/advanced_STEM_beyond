#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

struct Matrix {
	vector<vector<ll>> mat1;
	Matrix operator *(const Matrix& other) {
		vector<vector<ll>> mat2 = other.mat1;
		vector<vector<ll>> ans(mat1.size());
		for (int i = 0; i < ans.size(); ++i) {
			ans[i].resize(mat2[0].size());
			for (int j = 0; j < ans[i].size(); ++j) {
				ans[i][j] = 0;
				for (int k = 0; k < mat1[0].size(); ++k) {
					ans[i][j] += mat1[i][k] * mat2[k][j];
					ans[i][j] %= MOD;
				}
			}
		}
		Matrix m;
		m.mat1 = ans;
		return m;
	}

	Matrix identity (int n) {
		Matrix ans;
		ans.mat1.resize(n);
		for (int i = 0; i < n; ++i) {
			ans.mat1[i].resize(n);
			for (int j = 0; j < n; ++j) ans.mat1[i][j] = (i == j);
		}
		return ans;
	}

	Matrix binpow (ll powr) {
		Matrix res = {mat1}, ans = identity(mat1.size());
		while (powr > 0) {
			if (powr & 1) ans = ans * res;
			res = res * res;
			powr >>= 1;
		}
		return ans;
	}
};

bool valid (ll x, ll y) {
	return !((__builtin_popcountll(x ^ y)) % 3);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Matrix adj;
	adj.mat1.resize(n);
	for (int i = 0; i < n; ++i) {
		adj.mat1[i].resize(n);
		for (int j = 0; j < n; ++j) adj.mat1[i][j] = valid(a[i], a[j]);
	}
	Matrix ans = adj.binpow(k - 1);
	ll res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			res += ans.mat1[i][j];
			res %= MOD;
		}
	cout << res;
}