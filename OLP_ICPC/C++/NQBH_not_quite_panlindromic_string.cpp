#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int n0 = 0, n1 = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == '0') ++n0;
			else ++n1;
		int n_pair = n0 / 2 + n1 / 2;
		if (n_pair < k) cout << "NO\n";
		else if (n_pair == k) cout << "YES\n";
		else {
			while (k) {
				if (n0 < n1) n1 -= 2;
				else n0 -= 2;
				--k;
			}
			if (abs(n0 - n1) >= 2) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}