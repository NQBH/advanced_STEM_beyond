#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	vector<string> c(n);
	for (string &s : c) cin >> s;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			if (c[i][j] == 'C') ++cnt;
		ans += cnt * (cnt - 1) / 2;
	}
	for (int j = 0; j < n; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (c[i][j] == 'C') ++cnt;
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans << '\n';
}