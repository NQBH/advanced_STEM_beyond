#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		string s;
		cin >> n >> m >> s;
		map<char, int> f;
		for (char c : s) ++f[c];
		for (char c = 'A'; c <= 'G'; ++c)
			if (f[c] < m) ans += m - f[c];
		cout << ans << '\n';		
	}
}