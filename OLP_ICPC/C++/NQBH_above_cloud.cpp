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
		bool yes = false;
		++f[s[0]];
		++f[s[n - 1]];
		for (int i = 1; i < n - 1; ++i) {
			++f[s[i]];
			if (f[s[i]] > 1) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
}