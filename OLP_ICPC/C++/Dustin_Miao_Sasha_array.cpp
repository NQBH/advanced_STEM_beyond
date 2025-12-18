#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using Matrix = array<array<ll, 2>, 2>;
#define f first
#define s second

const int MAXN = 1e5 + 1;
const ll MOD = 1e9 + 7;

// multiply 2 2 x 2 matrices
Matrix multiply(const Matrix &a, const Matrix &b) {
	return {(a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD,
	        (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD,
	        (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD,
	        (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD};
}

// multiply a 1 x 1 matrix with a 2 x 2 matrix
pll multiply(const pll &a, const Matrix &b) {
	return {(a.f * b[0][0] + a.s * b[1][0]) % MOD,
	        (a.f * b[0][1] + a.s * b[1][1]) % MOD};
}

// returns {0, 1, 1, 1,} to the power of n
Matrix pow(ll n) {
	Matrix res = {1, 0, 0, 1}; // identity matrix
	Matrix base = {0, 1, 1, 1}; // Fibonacci matrix
	for ( ; n; n >>= 1) { // binary exponentiation (log n)
		if (n & 1) res = multiply(res, base);
		base = multiply(base, base);
	}
	return res;
}

int n, q;
pll tree[MAXN * 4];
ll lazy[MAXN * 4];

// return the pair-sum of a & b
pll merge(const pll &a, const pll &b) { return {(a.first + b.first) % MOD, (a.second + b.second) % MOD}; }

// push lazy update in t to its children
void pushdown(int t) {
	if (!lazy[t]) return;
	tree[t << 1] = multiply(tree[t << 1], pow(lazy[t]));
	lazy[t << 1] += lazy[t];
	tree[t << 1 | 1] = multiply(tree[t << 1 | 1], pow(lazy[t]));
	lazy[t << 1 | 1] += lazy[t];
	lazy[t] = 0;
}

// cycle range from l to r by v
void update(int l, int r, ll v, int t = 1, int tl = 1, int tr = n) {
	if (r < tl || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[t] = multiply(tree[t], pow(v));
		lazy[t] += v;
		return;
	}
	pushdown(t);
	int tm = (tl + tr) >> 1;
	update(l, r, v, t << 1, tl, tm);
	update(l, r, v, t << 1 | 1, tm + 1, tr);
	tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
}

// query sum from l to r
ll query(int l, int r, int t = 1, int tl = 1, int tr = n) {
	if (r < tl || tr < l) return 0;
	if (l <= tl && tr <= r) return tree[t].first;
	pushdown(t);
	int tm = (tl + tr) >> 1;
	return (query(l, r, t << 1, tl, tm) + query(l, r, t << 1 | 1, tm + 1, tr)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	fill_n(tree, MAXN * 4, pll{0, 1});
	for (int i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		update(i, i, a);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			ll v;
			cin >> l >> r >> v;
			update(l, r, v);
		} else if (t == 2) {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
}