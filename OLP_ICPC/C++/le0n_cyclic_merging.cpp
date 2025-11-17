#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
ll a[N];

int main() {
	int t, n, m, i;
	ll k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		m = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", a + i);
			if (a[i] > a[m]) m = i;
		}
		a[n] = a[0];
		k = -a[m];
		for (int i = 0; i < n; ++i) k += max(a[i], a[i + 1]);
		printf("%lld\n", k);
	}
}