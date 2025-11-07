#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<char, int> f;
		for (char c : s)
			++f[c];
		int f_min = 1e9, f_max = 0;
		char c_min = s[0], c_max = s[0];
		for (auto e : f) {
			if (e.second < f_min) {
				f_min = e.second;
				c_min = e.first;
			}
			if (e.second > f_max) {
				f_max = e.second;
				c_max = e.first;
			}
		}
		if (f_min == f_max) {
			for (int i = 0; i < n; ++i)
				if (s[i] != s[0]) {
					s[i] = s[0];
					break;
				}
		} else {
			for (int i = 0; i < n; ++i)
				if (s[i] == c_min) {
					s[i] = c_max;
					break;
				}
		}
		cout << s << '\n';
	}
}