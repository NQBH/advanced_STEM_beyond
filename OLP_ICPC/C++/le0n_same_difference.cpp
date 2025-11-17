#include <bits/stdc++.h>
using namespace std;

char s[100005];

int main() {
	int n, t, i, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		m = 0;
		for (i = 1; i < n; ++i) m += (s[i] != s[n]);
		printf("%d\n", m);
	}
}