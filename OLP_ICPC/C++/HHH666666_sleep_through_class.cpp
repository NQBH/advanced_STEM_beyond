#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			int ok = 1;
			for (int j = max(0, (int)i - k); j < i; ++j)
				if (s[j] == '1') {
					ok = 0;
					break;
				}
			ans += ok;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for (; t--;) solve();
}