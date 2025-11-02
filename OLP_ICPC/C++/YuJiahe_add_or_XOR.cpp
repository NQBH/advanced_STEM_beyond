#include <cstdio>
using namespace std;
int t, a, b, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		if (a > b) printf("%d\n", (a ^ 1) == b ? y : -1);
		else {
			int c0 = b - a, c1 = (b + 1 >> 1) - (a + 1 >> 1);
			printf("%lld\n", y > x ? 1ll * c0 * x : 1ll * (c0 - c1) * x + 1ll * c1 * y);
		}
	}
}