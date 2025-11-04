#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, tmp, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		ans += tmp + (tmp == 0);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}