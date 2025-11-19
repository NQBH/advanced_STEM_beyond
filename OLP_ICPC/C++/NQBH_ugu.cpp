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
		string t = s;
		sort(t.begin(), t.end());
		if (count(s.begin(), s.end(), '0') == n || count(s.begin(), s.end(), '1') == n || s == t) cout << "0\n";
		else {
			int ans = 0, turn = -1; // turn = -1: go down, turn = 1: go up
			for (int i = 0; i < n - 1; ++i) {
				if (turn == -1 && s[i] > s[i + 1]) {
					++ans;
					turn = -turn;
				}
				if (turn == 1 && s[i] < s[i + 1]) {
					++ans;
					turn = -turn;
				}
			}
			cout << ans << '\n';
		}
	}
}