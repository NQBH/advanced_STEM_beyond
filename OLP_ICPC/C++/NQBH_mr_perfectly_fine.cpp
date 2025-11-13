#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, MAX = 4e5 + 1, ans = MAX;
		cin >> n;
		bool ok1 = false, ok2 = false, ok = false;
		vector<int> m(n);
		vector<string> s(n);
		int mn1 = MAX, mn2 = MAX;
		for (int i = 0; i < n; ++i) {
			cin >> m[i] >> s[i];
			if (s[i] == "01") {
				ok1 = true;
				mn1 = min(mn1, m[i]);
			} else if (s[i] == "10") {
				ok2 = true;
				mn2 = min(mn2, m[i]);
			} else if (s[i] == "11") {
				ok = true;
				ans = min(ans, m[i]);
			}
		}
		if (ok || (ok1 && ok2)) {
			ans = min(ans, mn1 + mn2);
			cout << ans << '\n';
		} else cout << "-1\n";
	}
}