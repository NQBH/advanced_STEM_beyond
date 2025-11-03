#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y = 10;
		cin >> x;
		while (x) {
			y = min(y, x % 10);
			x /= 10;
		}
		cout << y << '\n';
	}
}