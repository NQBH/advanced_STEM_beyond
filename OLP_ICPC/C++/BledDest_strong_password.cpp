#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size(), idx = -1;
	for (int i = 0; i + 1 < n; ++i)
		if (s[i] == s[i + 1]) idx = i;
	if (idx == -1) {
		if (s.back() = 'a') cout << (s + "b") << '\n';
		else cout << (s + "a") << '\n';
	} else {
		string t = "a";
		if (s[idx] == 'a') t = "b";
		cout << s.substr(0, idx + 1) + t + s.substr(idx + 1) << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) solve();
}