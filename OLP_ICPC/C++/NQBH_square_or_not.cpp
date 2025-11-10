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
		int r = sqrt(n);
		if (r * r != n) cout << "NO\n";
		else if (n == 4 && s == "1111") cout << "YES\n";
		else {
			int i = 0;
			while (s[i] == '1') ++i;
			if (i == r + 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}