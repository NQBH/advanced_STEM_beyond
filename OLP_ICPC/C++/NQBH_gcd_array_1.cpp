#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int l, r, k;
		cin >> l >> r >> k;
		if (k == 0 && l == r) cout << (l == 1 ? "NO\n" : "YES\n");
		else cout << (r - l + 1 - r / 2 + (l - 1) / 2 <= k ? "YES\n" : "NO\n");
	}
}