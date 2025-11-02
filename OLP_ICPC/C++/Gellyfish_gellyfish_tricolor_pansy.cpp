#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (min(a, c) >= min(b, d)) printf("Gellyfish\n");
	else printf("Flower\n");
}

int t = 0;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve();
}