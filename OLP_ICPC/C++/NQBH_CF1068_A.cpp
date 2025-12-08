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
		int ans = 0, awake_until = -1;
		for (int i = 0; i < n; ++i)
			if (s[i] == '1') awake_until = max(awake_until, i + k);
		else {
			if (i > awake_until) ++ans;
		}
		cout << ans << '\n';
	}
}