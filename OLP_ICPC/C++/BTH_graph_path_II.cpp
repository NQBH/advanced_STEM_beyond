#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
using namespace std;
using ll = long long;

const int MAXN = 106;
const ll INF = 4e18;
int n, m, k;

struct Matrix {
	int n, m;
	ll d[MAXN][MAXN];

	Matrix (int _n, int _m) {
		n = _n, m = _m;
		REP(i, MAXN) REP(j, MAXN) d[i][j] = INF;
	}

	Matrix operator * (const Matrix &a) const {
		int x = n, y = m, z = a.m;
		Matrix res(x, z);
		REP(i, x) REP(j, y) REP(k, z) res.d[i][k] = min(res.d[i][k], d[i][j] + a.d[j][k]);
		return res;
	}

	Matrix operator ^ (int k) const {
		Matrix res(n, n), mul = *this;
		REP(i, n) res.d[i][i] = 0;
		while (k > 0) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    Matrix trans(n, n);
    FOR(i, 1, m) {
    	int x, y, w;
    	cin >> x >> y >> w;
    	--x, --y;
    	trans.d[x][y] = min(trans.d[x][y], (ll)w);
    }
    trans = trans ^ k;
    if (trans.d[0][n - 1] < INF) cout << trans.d[0][n - 1];
    else cout << -1;
}