#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
const int MOD = 1e9 + 7;

int64_t chmin(int64_t x, int64_t y) {
	if (x == -1) return y;
	if (y == -1) return x;
	return min(x, y);
}

class Matrix {
public:
	vector<vector<int64_t>> v;

	void print() {
		for (int i = 0; i < v.size(); ++i) {
			for (int j : v[i]) cout << j << ' ';
			cout << '\n';
		}
	}

	Matrix operator * (Matrix m1) const {
		Matrix ans(v);
		for (int i = 0; i < m1.v.size(); ++i)
			for (int j = 0; j < m1.v.size(); ++j) ans.v[i][j] = -1;
		for (int i = 0; i < m1.v.size(); ++i)
			for (int j = 0; j < m1.v.size(); ++j) {
				ans.v[i][j] = -1;
				for (int k = 0; k < m1.v.size(); ++k) {
					if (v[i][k] == -1 || m1.v[k][j] == -1) continue;
					ans.v[i][j] = chmin(v[i][k] + m1.v[k][j], ans.v[i][j]);
				}
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
		Matrix ans = *this, res = *this;
		while (x > 0) {
			if (x & 1) ans = res * ans;
			res = res * res;
			x >>= 1;
		}
		return ans;
	}

	Matrix (vector<vector<int64_t>> v) {
		this->v = v;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int64_t>> v(n);
    for (int i = 0; i < n; ++i) v[i].assign(n, -1);
    while (m--) {
    	int x, y, w;
    	cin >> x >> y >> w;
    	--x, --y;
    	v[x][y] = chmin(v[x][y], w);
    }
    Matrix fib = Matrix(v);
    fib = fib ^ (k - 1);
    cout << fib.v[0][n - 1];
}