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
		bool duplicate = false;
		for (int i = 0; i < s.size() - 1; ++i)
			if (s[i] == s[i + 1]) {
				duplicate = true;
				break;
			}
		if (duplicate) cout << "1\n";
		else cout << s.size() << '\n';		
	}
}