#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin >> n;
	string dummy;
    getline(cin, dummy);
    string old1 = "Google Developer Student Club";
    string old2 = "GDSC";
    string new1 = "Applied Programming Club";
    string new2 = "APC";
	while (n--) {
		string s, ans = "";
		getline(cin, s);
		for (int i = 0; i < s.size();) {
			bool replace = false;
			if (i + old1.size() <= s.size() && s.substr(i, old1.size()) == old1) {
				ans += new1;
				i += old1.size();
				replace = true;
			} else if (i + old2.size() <= s.size() && s.substr(i, old2.size()) == old2) {
				ans += new2;
				i += old2.size();
				replace = true;
			}
			if (!replace) {
				ans += s[i];
				++i;
			}
		}
		cout << ans << '\n';
	}
}