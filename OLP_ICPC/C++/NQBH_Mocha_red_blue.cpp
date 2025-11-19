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
		if (s.size() == 1) {
			if (s == "?") cout << "B\n";
			else cout << s << '\n';
			continue;
		}
		int pos = 0; // 1st position of ?
		while (s[pos] == '?') ++pos;
		for (int i = pos - 1; i >= 0; --i)
			if (s[i + 1] == 'R') s[i] = 'B';
			else s[i] = 'R';
		for (int i = pos + 1; i <= s.size(); ++i)
			if (s[i] == '?') {
				if (s[i - 1] == 'R') s[i] = 'B';
				else s[i] = 'R';
			}
		cout << s << '\n';
	}
}