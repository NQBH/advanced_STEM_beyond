#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt = 1;
		vector<int> a;
		for (int i = 1; i < (int)s.size(); ++i)
			if (s[i] != s[i - 1]) {
				a.push_back(cnt);
				cnt = 1;
			} else ++cnt;
		a.push_back(cnt);
		if (a.size() == 2) cout << "NO\n";
		else {
			bool ok = false;
			for (int i = 0; i < a.size() - 1; i += 2)
				if (a[i] == a[i + 1]) {
					ok = true;
					break;
				}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}
}
// WA test 2