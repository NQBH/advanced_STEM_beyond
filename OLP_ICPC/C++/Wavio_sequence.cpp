#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10010, INF = 2147483647;
int n, a[MAXN], f[MAXN], g[MAXN], L[MAXN]; // n: number of integers, a[]: given sequence, L[]: increasing sequence, f[] is as LIS[], g[] is as LDS[]

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

inline int min(int x, int y) {
	return x < y ? x : y; // return min{x, y}
}

int main() {
	int k, ans;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i) scanf("%d", a + i); // input n integers
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
		ans = 0;
		for (int i = 1; i <= n; ++i) // every element in a[] as middle & adjust
			if ((k = min(f[i], g[i])) > ans) ans = k;
		printf("%d\n", ans * 2 - 1); // output result
	}
}