#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		vector<int> fs(26, 0), ft(26, 0);
		for (char c : s) ++fs[c - 'a'];
		for (char c : t) ++ft[c - 'a'];
		bool ok = true;
		for (int i = 0; i < 26; ++i)
			if (fs[i] > ft[i]) {
				ok = false;
				cout << "Impossible\n";
				break;
			}
		if (!ok) continue;
		vector<int> extra(26, 0); // number of redundant characters
		for (int i = 0; i < 26; ++i) extra[i] = ft[i] -fs[i];
		string ans = "";
		for (char c : s) {
			for (int i = 0; i < (c - 'a'); ++i)
				while (extra[i] > 0) {
					ans += (char)('a' + i);
					--extra[i];
				}
			ans += c;
		}
		for (int i = 0; i < 26; ++i)
			while (extra[i] > 0) {
				ans += (char)('a' + i);
				--extra[i];
			}
		cout << ans << '\n';
	}
}