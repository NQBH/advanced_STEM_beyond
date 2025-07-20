#include <iostream>
using namespace std;
const int MAXN = 1e6 + 1, INF = 1e9 + 1; // since a_i in [10^9] for all i in [n]
int n, a[MAXN], f[MAXN], g[MAXN], L[MAXN];

int binary(int l, int r, int x) { // return number of elements in
	int mid;
	l = 0; r = n;
	while (l < r) {
		mid = (l + r) >> 1;
		if (L[mid + 1] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) L[i] = INF;
	L[0] = -INF - 1; // initialization
	for (int i = 1; i <= n; ++i) { // right to left in array a
		f[i] = binary(1, n, a[i]) + 1;
		if (a[i] < L[f[i]]) L[f[i]] = a[i];
	}
	for (int i = 1; i <= n; ++i) L[i] = INF;
	L[0] = -INF - 1; // initialization
	for (int i = n; i >= 1; i--) { // left to right in array a
		g[i] = binary(1, n, a[i]) + 1;
		if (a[i] < L[g[i]]) L[g[i]] = a[i];
	}
}