#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

vector<vector<ll>> mat(101, vector<ll>(101, 0));
vector<vector<ll>> mat_mul(vector<vector<ll>> mat1, vector<vector<ll>> mat2, ll sz) {
	vector<vector<ll>> mul(sz, vector<ll>(sz, 0));
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j) {
			int cur = 0;
			for (int k = 0; k < sz; ++k) {
				cur += (mat1[i][k] * mat2[k][j]) % MOD;
				cur %= MOD;
			}
			mul[i][j] = cur;
		}
	return mul;
}

ll mat_expo(vector<vector<ll>> pow, ll sz, ll n) {
	vector<vector<ll>> ans(sz, vector<ll>(sz, 0));
	for (int i = 0; i < sz; ++i) ans[i][i] = 1;
	while (n) {
		if (n & 1) ans = mat_mul(ans, pow, sz);
		pow = mat_mul(pow, pow, sz);
		n /= 2;
	}
	return ans[1][sz - 1];
}

int main() {
	int a, b, n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		++mat[a][b];
	}
	cout << mat_expo(mat, n + 1, k);
}