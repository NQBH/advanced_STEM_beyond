#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, q, l, r;
		string s;
		cin >> n >> q >> s;
		s = " " + s;
		vector<int> n0(n + 1, 0), n1(n + 1, 0); // number of 0s & 1s from index 1 to index i
		for (int i = 1; i <= n; ++i) {
			n0[i] = n0[i - 1];
			n1[i] = n1[i - 1];
			if (s[i] == '0') ++n0[i];
			else ++n1[i];
		}
		for (int i = 0; i < q; ++i) {
			cin >> l >> r;
			if (l == 1 && r == n) cout << "NO\n";
			else {
				if ((s[l] == '0' && n0[l - 1]) || (s[l] == '1' && n1[l - 1])) cout << "YES\n";
				else if ((s[r] == '0' && n0[n] - n0[r] >= 1) || (s[r] == '1' && n1[n] - n1[r] >= 1)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}