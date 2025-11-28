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
		if (n == 1) cout << "NO\n";
		else {
			string s0 = s;
			reverse(s.begin(), s.end());
			if (s > s0) cout << "YES\n";
			else if (k == 0) cout << "NO\n";
			else {
				bool ok = false;
				for (int i = 1; i < n; ++i)
					if (s[i] != s[0]) {
						ok = true;
						break;
					}
				cout << (ok ? "YES\n" : "NO\n");
			}
		}
	}
}