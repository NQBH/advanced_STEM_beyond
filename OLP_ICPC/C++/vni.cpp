#include <bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;
ll a[N + 2], f[N + 2], g[N + 2];
int n, q, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		f[n] = 0;
		g[n] = a[n];
		for (int i = n - 1; i > 0; --i) {
			f[i] = f[i + 1] + max(g[i + 1] - a[i], 0LL);
			g[i] = max(g[i + 1], a[i]);
		}
		cin >> q;
		for (int x, i = 0; i < q; ++i) {
			cin >> x;
			cout << f[x] << "\n";
		}
	}
}