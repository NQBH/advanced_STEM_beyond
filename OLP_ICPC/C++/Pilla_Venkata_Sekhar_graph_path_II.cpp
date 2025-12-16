#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
vector<vector<ll>> mat(101, vector<ll>(101, 0));

vector<vector<ll>> mat_mul(vector<vector<ll>> mat1, vector<vector<ll>> mat2, ll sz) {
	vector<vector<ll>> mul(sz, vector<ll>(sz, 0));
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j) {
			ll cur = 0;
			for (int k = 0; k < sz; ++k)
				if (mat1[i][k] > 0 && mat2[k][j] > 0) {
					if (cur) cur = min(cur, (mat1[i][k] + mat2[k][j]));
					else cur = mat1[i][k] + mat2[k][j];
				}
			mul[i][j] = cur;
		}
	return mul;
}

ll mat_expo(vector<vector<ll>> pow, ll sz, ll n) {
	vector<vector<ll>> ans(sz, vector<ll>(sz, 0));
	int check = 0;
	while (n) {
		if (n & 1) {
			if (check) ans = mat_mul(ans, pow, sz);
			else {
				check = 1;
				for (int i = 0; i < sz; ++i)
					for (int j = 0; j < sz; ++j) ans[i][j] = pow[i][j];
			}
		}
		pow = mat_mul(pow, pow, sz);
		n >>= 1;
	}
	if (ans[1][sz - 1]) return ans[1][sz - 1];
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	ll a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (!mat[a][b]) mat[a][b] = c;
		else mat[a][b] = min(mat[a][b], c);
	}
	cout << mat_expo(mat, n + 1, k);
}