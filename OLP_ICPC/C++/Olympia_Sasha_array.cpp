#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("Ofast") // if drop this, TLE on test 18 CF 
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

struct Matrix {
	ll arr[2][2];
	Matrix operator*(Matrix m1) {
		Matrix ans;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				ans.arr[i][j] = 0;
				for (int k = 0; k < 2; ++k) ans.arr[i][j] += (arr[i][k] * m1.arr[k][j]) % MOD;
				ans.arr[i][j] %= MOD;
			}
		return ans;
	}

	Matrix operator + (Matrix m1) {
		Matrix ans;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				ans.arr[i][j] = arr[i][j] + m1.arr[i][j];
				if (ans.arr[i][j] >= MOD) ans.arr[i][j] -= MOD;
			}
		return ans;
	}
};

Matrix powr(Matrix m, ll powr) {
	Matrix ans = {{{1, 0}, {0, 1}}}, res = m;
	while (powr > 0) {
		if (powr & 1) ans = ans * res;
		res = res * res;
		powr >>= 1;
	}
	return ans;
}

vector<Matrix> vec;
vector<ll> addLater;
Matrix fib = {{{0, 1}, {1, 1}}};

void push(ll v) {
	addLater[2 * v + 1] += addLater[v];
	vec[2 * v + 1] = vec[2 * v + 1] * powr(fib, addLater[v]);
	addLater[2 * v] += addLater[v];
	vec[2 * v] = vec[2 * v] * powr(fib, addLater[v]);
    addLater[v] = 0;
}

void upd(int dum, ll tl, int tr, int l, int r, ll val) {
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		addLater[dum] += val;
		vec[dum] = vec[dum] * powr(fib, val);
		return;
	}
	push(dum);
	int mid = (tl + tr) >> 1;
	upd(2 * dum, tl, mid, l, r, val);
	upd(2 * dum + 1, mid + 1, tr, l, r, val);
	vec[dum] = vec[2 * dum] + vec[2 * dum + 1];
}

void upd(int l, int r, ll val) {
	upd(1, 0, (int)vec.size() / 2 - 1, l, r, val);
}

Matrix get(int dum, int tl, int tr, int &l, int &r) {
	if (tl > r || tr < l) return {{{0, 0}, {0, 0}}};
	if (tl >= l && tr <= r) return vec[dum];
	push(dum);
	int tm = (tl + tr) >> 1;
	return get(dum * 2, tl, tm, l, r) + get(dum * 2 + 1, tm + 1, tr, l, r);
}

Matrix get(int l, int r) {
	return get(1, 0, (int)vec.size() / 2 - 1, l, r);
}

void resz(ll n) {
	ll sz = ((1 << (ll)ceil(log2(n))));
	vec.assign(sz * 2, {{{1, 0}, {0, 1}}});
	addLater.assign(sz * 2, 0);
}

class CSashaArray {
public:
	void solve(std::istream &in, std::ostream &out) {
		ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, m;
        in >> n >> m;
        resz(n);
        for (int i = 0; i < n; ++i) {
        	int x;
        	in >> x;
        	upd(i, i, x);
        }
        while (m--) {
        	int t;
        	in >> t;
        	if (t == 2) {
        		int u, v;
        		in >> u >> v;
        		--u, --v;
        		out << get(u, v).arr[0][1] << '\n';
        	} else {
        		int l, r, x;
        		in >> l >> r >> x;
        		--l, --r;
        		upd(l, r, x);
        	}
        }
	}
};

int main() {
	CSashaArray solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
}