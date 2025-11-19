#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		map<char, int> f;
		for (int i = 0; i < 4 * n; ++i)
			if (s[i] == 'A') ++f['A'];
			else if (s[i] == 'B') ++f['B'];
			else if (s[i] == 'C') ++f['C'];
			else if (s[i] == 'D') ++f['D'];
		int ans = min(f['A'], n) + min(f['B'], n) + min(f['C'], n) + min(f['D'], n);
		cout << ans << '\n';
	}
}