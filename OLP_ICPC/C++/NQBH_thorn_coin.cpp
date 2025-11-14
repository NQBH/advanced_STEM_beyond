#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		string s;
		cin >> n >> s;
		int n_thorn = 0;
		for (int i = 1; i < n; ++i) {
			if (s[i] == '@') {
				++ans;
				n_thorn = 0;
			} else if (s[i] == '*') ++n_thorn;
			else n_thorn = 0;
			if (n_thorn == 2) break;
		}
		cout << ans << '\n';
	}
}