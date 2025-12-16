#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
const int MOD = 1e9 + 7;

class Matrix {
public:
	vector<vector<int64_t>> v;
	void print() {
		for (int i = 0; i < v.size(); ++i) {
			for (int j : v[i]) cout << j << ' ';
			cout << '\n';
		}
	}
	Matrix operator* (Matrix m1) const {
		Matrix ans(v);
		for (int i = 0; i < m1.v.size(); ++i)
			for (int j = 0; j < m1.v.size(); ++j) ans.v[i][j] = 0;
		for (int i = 0; i < m1.v.size(); ++i)
			for (int j = 0; j < m1.v.size(); ++j)
				for (int k = 0; k < m1.v.size(); ++k) {
					ans.v[i][j] += (v[i][k] * m1.v[k][j]) % MOD;
					ans.v[i][j] %= MOD;
				}
		return ans;
	}
	Matrix identity (int64_t n) {
		vector<vector<int64_t>> vec(n);
		for (int i = 0; i < n; ++i) {
			vec[i].resize(n);
			for (int j = 0; j < n; ++j) vec[i][j] = (i == j);
		}
		return Matrix(vec);
	}
	Matrix operator^ (int64_t x) {
		Matrix ans = identity(v.size()), res = *this;
		while (x > 0) {
			if (x & 1) ans = res * ans;
			res = res * res;
			x /= 2;
		}
		return ans;
	}
	Matrix (vector<vector<int64_t>> v) {
		this->v = v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int64_t>> v(n);
	for (int i = 0; i < n; ++i) v[i].assign(n, 0);
	while (m--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		++v[x][y];
	}
	Matrix fib = Matrix(v);
	fib = fib^(k);
	cout << fib.v[0][n - 1];
}