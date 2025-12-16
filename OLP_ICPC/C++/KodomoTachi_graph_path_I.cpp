#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

#define MAX_SIZE 100 
#define ll long long

struct Matrix {
	int m, n; // m = số hàng, n = số cột
	ll d[MAX_SIZE][MAX_SIZE];
	Matrix (int _m = 0, int _n = 0) {
		m = _m; n = _n;
		memset(d, 0, sizeof d);
	}

	Matrix operator + (const Matrix &a) const { // phép cộng ma trận
		Matrix res(m, n);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				res.d[i][j] = d[i][j] + a.d[i][j];
				if (res.d[i][j] >= MOD) res.d[i][j] -= MOD;
			}
		return res;
	}

	Matrix operator * (const Matrix &a) const { // phép nhân ma trận
		ll x = m, y = n, z = a.n;
		Matrix res(x, z);
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				for (int k = 0; k < z; ++k) res.d[i][k] = (res.d[i][k] + 1LL * d[i][j] * a.d[j][k]) % MOD;
		return res;
	}

	Matrix operator ^ (ll k) const { // phép luỹ thừa ma trận
		Matrix res(n, n);
		for (int i = 0; i < n; ++i) res.d[i][i] = 1;
		Matrix mul = *this;
		while (k > 0) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}
		return res;
	}
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	Matrix t(n, n);
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		++t.d[x - 1][y - 1]; // attention: maybe have duplicate edge
	}
	t = t ^ k;
	cout << t.d[0][n - 1];
}