#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x == y || x == y + 1 || y == 1) cout << -1 << '\n';
		else if (x < y) cout << 2 << '\n';
		else cout << 3 << '\n';
	}
}