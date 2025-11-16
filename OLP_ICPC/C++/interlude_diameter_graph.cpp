#include <stdio.h>
inline void Solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if ((n - 1ll)*n >> 1 < m || m < n - 1) {
		puts("NO");
		return;
	}
	if (n == 1) {
		if (k > 1) puts("YES");
		else puts("NO");
	} else if (m < (n - 1ll) * n >> 1) {
		if (k > 3) puts("YES");
		else puts("NO");
	} else if (k > 2) puts("YES");
	else puts("NO");
}

int main() {
	int t;
	scanf("%d", &t);
	for (register int i = 0; i != t; ++i) Solve();
}