#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y, val = 0;
		cin >> x;
		for (int i = 1; i < x; ++i) {
			if (gcd(x, i) + i > val) val = gcd(x, i) + i;
			y = i;
		}
		cout << y << '\n';
	}
}