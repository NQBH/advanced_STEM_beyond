#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &n);
		printf(((long long)b * n <= a || b >= a) ? "1\n" : "2\n");
	}
}