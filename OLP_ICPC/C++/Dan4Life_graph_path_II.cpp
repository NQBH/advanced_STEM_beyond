#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll LINF = 4e18;
int n, m, k, x, y, z;

struct Matrix {
	ll a[110][110];
	Matrix (ll v = 0) {
		for (int i = 0; i < 110; ++i) fill(a[i], a[i] + 110, v);
	}
};

Matrix M(LINF), I(LINF);

Matrix mult(Matrix x, Matrix y) {
	Matrix z(LINF);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) z.a[i][j] = min(z.a[i][j], x.a[i][k] + y.a[k][j]);
	return z;
}

Matrix pow(Matrix x, int b) {
	if (!b) return I;
	if (b == 1) return x;
	Matrix y = pow(x, b / 2);
	y = mult(y, y);
	if (b & 1) y = mult(y, x);
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	while (m--) {
		cin >> x >> y >> z;
		--x, --y;
		M.a[x][y] = min(M.a[x][y], (ll)z);
	}
	cout << (pow(M, k).a[0][n - 1] < LINF ? pow(M, k).a[0][n - 1] : -1);
}