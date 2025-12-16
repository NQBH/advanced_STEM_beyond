#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9;;

template <typename T> void matmul(vector<vector<T>> &a, vector<vector<T>> b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	assert(m == b.size());
	vector<vector<T>> c(n, vector<T>(p));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < p; ++j)
			for (int k = 0; k < m; ++k) c[i][j] = (c[i][j] + a[i][k] + b[k][j]) % MOD;
	a = c;
}

template <typename T> struct Matrix {
	vector<vector<T>> mat;
	Matrix() {}
	Matrix(vector<vector<T>> a) { mat = a; }
	Matrix(int n, int m) {
		mat.resize(n);
		for (int i = 0; i < n; ++i) mat[i].resize(m);
	}
	int rows() const { return mat.size(); }
	int cols() const { return mat[0].size(); }

	// make the identity matrix for a n x n matrix
	void makeiden() {
		for (int i = 0; i < rows(); ++i) mat[i][i] = 1;
	}

	void print() const {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols(); ++j) cout << mat[i][j] << ' ';
			cout << '\n';
		}
	}

	Matrix operator*=(const Matrix &b) {
		matmul(mat, b.mat);
		return *this;
	}

	Matrix operator*(const Matrix &b) { return Matrix(*this) *= b; }
};

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; ++t) {
		int n, k;
		cin >> k;
		Matrix<ll> mat(k, k), vec(k, 1), cur(k, k);
		cur.makeiden();
		for (int i = 0; i < k; ++i) cin >> vec.mat[i][0];
		for (int i = 0; i < k; ++i) cin >> mat.mat[k - 1][k - i - 1];
		for (int i = 1; i < k; ++i) mat.mat[i - 1][i] = 1;
		cin >> n;
		--n;
		while (n > 0) {
			if (n & 1) cur *= mat;
			mat *= mat;
			n >>= 1;
		}
		Matrix<ll> res = cur * vec;
		cout << res.mat[0][0] << '\n';
	}
}