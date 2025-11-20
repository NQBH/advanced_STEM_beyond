#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int t, n, a[maxn];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if (a[1]) {
		printf("%d ", n + 1);
		for (int i = 1; i <= n; ++i) printf("%d ", i);
		return;
	}
	for (int i = 1; i < n; ++i)
		if (!a[i] && a[i + 1]) {
			for (int j = 1; j <= i; ++j) printf("%d ", j);
			printf("%d ", n + 1);
			for (int j = i + 1; j <= n; ++j) printf("%d ", j);
			return;
		}
	for (int i = 1; i <= n; ++i) printf("%d ", i);
	printf("%d ", n + 1);
}

int main() {
	scanf("%d", &t);
	while (t--) solve(), puts("");
}