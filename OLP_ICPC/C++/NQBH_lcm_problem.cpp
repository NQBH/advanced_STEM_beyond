#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		if (r >= 2 * l) cout << l << ' ' << 2 * l << '\n';
		else cout << "-1 -1\n";
	}
}