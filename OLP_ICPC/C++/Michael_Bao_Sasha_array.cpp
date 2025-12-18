#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

ll add(ll a, ll b) { return (a + b) % MOD; }
ll mult(ll a, ll b) { return a * b % MOD; }

struct Matrix {
	array<array<ll, 2>, 2> a;
	Matrix() { a = {{{0, 0}, {0, 0}}}; }
	Matrix operator*(const Matrix &o) const {
		Matrix res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k) res.a[i][j] = add(res.a[i][j], mult(a[i][k], o.a[k][j]));
		return res;
	}

	Matrix operator+(const Matrix &o) const {
		Matrix res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) res.a[i][j] = add(a[i][j], o.a[i][j]);
		return res;
	}

	bool operator==(const Matrix &o) const {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				if (a[i][j] != o.a[i][j]) return false;
		return true;
	}

	void print() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) cout << a[i][j] << " \n"[j == 1];
	}
};

Matrix fib(ll k) {
	Matrix res, base;
	res.a = {{{1, 0}, {0, 1}}};
	base.a = {{{1, 1}, {1, 0}}};
	for (; k; k >>= 1, base = base * base)
		if (k & 1) res = res * base;
	return res;
}

template <class T, int n>
struct LazySeg {
	static_assert(__builtin_popcount(n) == 1);
	const T ID = Matrix();
	T lazyID;
	T cmb(T a, T b) {
		return a + b;
	}
	T seg[2 * n], lazy[2 * n];
	LazySeg() {
		lazyID.a = {{{1, 0}, {0, 1}}};
		for (int i = 0; i < 2 * n; ++i) {
			seg[i] = ID;
			lazy[i] = lazyID;
		}
	}
	void push(int p, int l, int r) {
		seg[p] = seg[p] * lazy[p];
		if (l != r) {
			lazy[2 * p] = lazy[2 * p] * lazy[p];
			lazy[2 * p + 1] = lazy[2 * p + 1] * lazy[p];
		}
		lazy[p] = lazyID;
	}
	void pull(int p) {
		seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
	}
	void build(vector<T> &v, int p = 1, int l = 0, int r = n - 1) {
		seg[p] = ID;
		lazy[p] = lazyID;
		if (l == r) {
			if (size(v) > l) seg[p] = v[l];
		} else {
			int m = (l + r) >> 1;
			build(v, 2 * p, l, m);
			build(v, 2 * p + 1, m + 1, r);
			pull(p);
		}
	}
	void upd(int lo, int hi, T inc, int p = 1, int l = 0, int r = n - 1) {
		push(p, l, r);
		if (lo > r || l > hi) return;
		if (lo <= l && r <= hi) {
			lazy[p] = inc;
			push(p, l, r);
			return;
		}
		int m = (l + r) >> 1;
		upd(lo, hi, inc, 2 * p, l, m);
		upd(lo, hi, inc, 2 * p + 1, m + 1, r);
		pull(p);
	}
	T query(int lo, int hi, int p = 1, int l = 0, int r = n - 1) {
		push(p, l, r);
		if (lo > r || l > hi) return ID;
		if (lo <= l && r <= hi) return seg[p];
		int m = (l + r) >> 1;
		return cmb(query(lo, hi, 2 * p, l, m), query(lo, hi, 2 * p + 1, m + 1, r));
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<Matrix> v(n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		v[i] = fib(a);
	}
	LazySeg<Matrix, 1 << 17> seg;
	seg.build(v);

	while (q--) {
		int a;
		cin >> a;
		if (a == 1) {
			int l, r;
			ll x;
			cin >> l >> r >> x;
			seg.upd(l, r, fib(x));
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg.query(l, r).a[0][1] << '\n';
		}
	}
}