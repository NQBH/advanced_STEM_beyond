#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Mat {
	int n, m;
	vector<vector<ll>> mat;

	Mat (int _n, int _m) {
		n = _n, m = _m;
		mat.resize(n, vector<ll>(m));
	}

	Mat(vector<vector<ll>> v) {
		mat = v;
		n = (int)v.size(), m = (int)v[0].size();
	}
};

Mat ID (int n) {
	Mat ans(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) ans.mat[i][j] = 2e18;
	return ans;
}

Mat mul(Mat a, Mat b) {
	Mat ans = ID(a.n);
	for (int i = 0; i < a.n; ++i)
		for (int j = 0; j < b.m; ++j)
			for (int k = 0; k < a.m; ++k) ans.mat[i][j] = min(ans.mat[i][j], a.mat[i][k] + b.mat[k][j]);
	return ans;
}

Mat exp(Mat a, ll b) {
	Mat ans = ID(a.n);
	for (int i = 0; i < a.n; ++i) ans.mat[i][i] = 0;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    Mat a = ID(n);
    while (m--) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	a.mat[x - 1][y - 1] = min(a.mat[x - 1][y - 1], (ll)z);
    }
    a = exp(a, k);
    cout << (a.mat[0][n - 1] > 1e18 ? -1 : a.mat[0][n - 1]) << '\n';
}