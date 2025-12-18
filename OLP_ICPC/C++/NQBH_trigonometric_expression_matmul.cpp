#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Matrix {
	ll mat[2][2];
	Matrix() {
		mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
	}
};

Matrix multiply(Matrix A, Matrix B, ll m) {
	Matrix C;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j]) % m + m) % m;
	return C;
}

Matrix power(Matrix A, ll p, ll m) {
	Matrix res;
	res.mat[0][0] = 1, res.mat[1][1] = 1; // identity matrix
	A.mat[0][1] %= m;
	while (p > 0) {
		if (p & 1) res = multiply(res, A, m);
		A = multiply(A, A, m);
		p >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (!n) cout << 2 % m << '\n';
		else if (n == 1) cout << 4 % m << '\n';
		else {
			Matrix A;
			A.mat[0][0] = 4, A.mat[0][1] = -1, A.mat[1][0] = 1, A.mat[1][1] = 0;
			A = power(A, n - 1, m); // compute A^{n - 1}
			ll S0 = 2, S1 = 4; // base case
			ll ans = ((A.mat[0][0] * S1) % m + (A.mat[0][1] * S0) % m) % m;
			if (ans < 0) ans += m;
			cout << ans << '\n';
		}
	}
}