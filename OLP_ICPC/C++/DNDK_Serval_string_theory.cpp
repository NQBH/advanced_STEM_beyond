#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		bool trung = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != s[0]) {
				trung = false;
			}
		}
		if (trung) {
			cout << "NO" << endl;
			continue;
		}
		string m = s;
		reverse(m.begin(), m.end());
		if (s < m) {
			cout << "YES" << endl;
		} else {
			if (k >= 1) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
	}
}