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
		bool ok = true;
		int n1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (n1 >= k) {
					ok = false;
					break;
				}
				n1 = 0;
			} else ++n1;
		}
		if (n1 >= k) ok = false;
		if (!ok) cout << "NO\n";
		else {
			cout << "YES\n";
			vector<int> b(n);
			int a = 1;
			for (int i = 0; i < n; ++i)
				if (s[i] == '1') {
					b[i] = a;
					++a;
				}
			for (int i = 0; i < n; ++i)
				if (s[i] == '0') {
					b[i] = a;
					++a;
				}
			for (int i : b) cout << i << ' ';
			cout << '\n';
		}
	}
}