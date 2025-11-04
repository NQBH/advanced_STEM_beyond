#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, a, b, c, d;

int main() {
	for (scanf("%d", &t); t--; ) {
		scanf("%d%d%d%d", &a, &b, &c, &d), c -= a, d -= b;
		if (a > b) swap(a, b); if (c > d) swap(c, d);
		puts((a + 1 << 1) >= b && (c + 1 << 1) >= d ? "YES" : "NO");
	}
}