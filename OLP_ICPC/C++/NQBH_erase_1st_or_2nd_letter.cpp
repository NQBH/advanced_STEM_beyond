#include <bits/stdc++.h>
using namespace std;

int ans;
set<string> S = {};

void solve(string s) {
	if (s.empty()) return;
	int n = s.size();
	if (S.count(s)) {
		if (s.size() == 1) return;
		else {
			solve(s.substr(1, n - 1));
			solve(s[0] + s.substr(2, n - 2));
		}
	} else {
		S.insert(s);
		++ans;
		solve(s.substr(1, n - 1));
		solve(s[0] + s.substr(2, n - 2));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		ans = 0;
		solve(s);
		cout << ans << '\n';
	}
}
// unfinished