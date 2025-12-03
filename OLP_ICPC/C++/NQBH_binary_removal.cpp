#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int pos00 = -1, pos11 = -1;
		for (int i = 0; i < s.size() - 1; ++i)
			if (s[i] == '1' && s[i + 1] == '1') {
				pos11 = i;
				break;
			}
		for (int i = s.size() - 1; i >= 1; --i)
			if (s[i] == '0' && s[i + 1] == '0') {
				pos00 = i;
				break;
			}
		if (pos00 != -1 && pos11 != -1 && pos11 < pos00) cout << "NO\n";
		else cout << "YES\n";		
	}
}