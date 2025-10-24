#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int> a(q);
		for (int &x : a) cin >> x;

		bool allA = true ; // s full of A
		for (char c : s)
			if (c == 'B') {
				allA = false;
				break;
			}
		if (allA) {
			for (int &x : a) cout << x << '\n';
			continue;
		}

		bool allB = true; // s full of B
		for (char c : s)
			if (c == 'A') {
				allB = false;
				break;
			}
		if (allB) {
			for (int &x : a) cout << __lg(x) + 1 << '\n';
			continue;
		}
		// dp[i][a] = min number steps for a to reach 0 from machine i
		vector<vector<int>> dp(n + 1, vector<int>(1001, -1));

		for (int i = 1; i <= n; ++i) dp[i][0] = 0; // a = 0 already
		for (int a = 1; a <= 1000; ++a)
			for (int i = 1; i <= n; ++i) {
				int a_next = (s[i - 1] == 'A') ? a - 1 : a / 2;
				int next_machine = (i % n) + 1;
				dp[i][a] = 1 + dp[next_machine][a_next];
			}

		for (int i = 0; i < q; ++i) {
			int tmp = a[i];
			int pos = 1, ans = 0;
			set<pair<int, int>> visited; // pair (pos machine, a)
			while (tmp > 1000 && ans < 1000) {
				if (visited.count({pos, tmp})) break; // same items 2x: cycle
				visited.insert({pos, tmp});
				if (s[pos - 1] == 'A') --tmp;
				else tmp >>= 1;
				++ans;
				pos = (pos % n) + 1; // next machine
			}
			if (tmp <= 1000) ans += dp[pos][tmp];
			else {
				while (tmp) {
					if (s[pos - 1] == 'A') --tmp;
					else tmp /= 2;
					++ans;
					pos = (pos % n) + 1;
				}
			}
			cout << ans << '\n';
		}
	}
}