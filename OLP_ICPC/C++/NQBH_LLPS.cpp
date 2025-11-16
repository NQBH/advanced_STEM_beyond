#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	map<char, int> f;
	for (int i = 0; i < s.size(); ++i) ++f[s[i]];
	for (char c = 'z'; c >= 'a'; --c)
		if (f[c]) {
			for (int i = 0; i < f[c]; ++i) cout << c;
			break;
		}
}