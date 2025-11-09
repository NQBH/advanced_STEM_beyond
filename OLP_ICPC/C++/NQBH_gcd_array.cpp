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
		else { // cf. num of odds vs. k
			int n_odd;
			if (l % 2 != r % 2) n_odd = (r - l + 1) / 2;
			else if (l & 1) n_odd = (r - l) / 2 + 1;
			else n_odd = (r - l) / 2;
			cout << (n_odd <= k ? "YES\n" : "NO\n");
		}
	}
}