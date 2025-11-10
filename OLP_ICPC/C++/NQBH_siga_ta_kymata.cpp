#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int &x : p) cin >> x;
		string x;
		cin >> x;
		if (x[0] == '1' || x.back() == '1') {
			cout << "-1\n";
			continue;
		}
		bool ok = true;
		int pos1 = 1, posn = 1;
		for (int i = 0; i < n; ++i) {
			if (p[i] == 1) {
				pos1 = i;
			}
			if (p[i] == n) {
				posn = i;
			}
		}
		int n1 = 0;
		for (int i = 0; i < x.size(); ++i) {
			if (x[i] == '1') {
				++n1;
				if (i == pos1 || i == posn) {
					ok = false;
					break;
				}
			}
		}
		if (n1 == 0) {
			cout << "0\n";
			continue;
		}
		if (!ok) cout << "-1\n";
		else {
			cout << "5\n";
			cout << "1 " << pos1 + 1 << '\n';
			cout << pos1 + 1 << ' ' << n << '\n';
			cout << min(pos1 + 1, posn + 1) << ' ' << max(pos1 + 1, posn + 1) << '\n';
			cout << "1 " << posn + 1 << '\n';
			cout << posn + 1 << ' ' << n << '\n';
		}
	}
}