#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		if (w == 0 && b == 0) {
			cout << "YES\n";
			continue;
		}
		int nw = k1 + k2, nb = 2 * n - k1 - k2;
		if (nw >= 2 * w && nb >= 2 * b) cout << "YES\n";
		else cout << "NO\n";
	}
}