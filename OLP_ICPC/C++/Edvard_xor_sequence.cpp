#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 101, mod = 1000000007;
int n;
ll k, a[N];

bool read() {
	if (!(cin >> n >> k)) return false;
	for (int i = 0; i < n; ++i) assert(cin >> a[i]);
	return true;
}

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int mul(int a, int b) { return int(a * 1ll * b % mod); }

int count(ll x) {
	int ans = 0;
	while (x) {
		++ans;
		x &= x - 1;
	}
	return ans;
}

void mul(int a[N][N], int b[N][N], int n) {
	static int c[N][N];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < n; ++k) inc(c[i][j], mul(a[i][k], b[k][j]));
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) a[i][j] = c[i][j];
}

void bin_pow(int a[N][N], ll b, int n) {
	static int ans[N][N];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) ans[i][j] = i == j;
	while (b) {
		if (b & 1) mul(ans, a, n);
		mul(a, a, n);
		b >>= 1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) a[i][j] = ans[i][j];
}

void solve() {
	static int a[N][N];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			a[i][j] = count(::a[i] ^ ::a[j]) % 3 == 0;
		a[i][n] = 1;
	}
	bin_pow(a, k, n + 1);
	int ans = 0;
	for (int i = 0; i <= n; ++i) inc(ans, a[i][n]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (read()) solve();
}