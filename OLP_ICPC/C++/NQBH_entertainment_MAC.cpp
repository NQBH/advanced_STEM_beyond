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
		if (s[0] < s.back()) cout << s << '\n';
		else {
			string r = s;
			reverse(s.begin(), s.end());
			if (s < r) cout << s + r << '\n';
			else cout << r << '\n';
		}
	}
}