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
		map<char, int> f;
		for (char c : s) {
			++f[c];
			if (f[c] == 1) ans += 2;
			else ++ans;
		}
		cout << ans << '\n';
	}
}