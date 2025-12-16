#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int n, m, k, x, y;

struct Matrix {
	ll a[110][110];
	Matrix() {
		for (int i = 0; i < 110; ++i) fill(a[i], a[i] + 110, 0ll);
	}
};

Matrix M, I;

Matrix mult(Matrix x, Matrix y) {
	Matrix z;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) z.a[i][j] += x.a[i][k] * y.a[k][j], z.a[i][j] %= MOD;
	return z;
}

Matrix pow(Matrix x, int b) {
	if (!b) return I;
	Matrix y = pow(x, b / 2);
	y = mult(y, y);
	if (b & 1) y = mult(y, x);
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) I.a[i][i] = 1;
	while (m--) {
		cin >> x >> y;
		--x, --y;
		++M.a[x][y];
	}
	cout << pow(M, k).a[0][n - 1];
}