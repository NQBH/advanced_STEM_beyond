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
		if (s.size() == 1) {
			if (s == "a") s += 'b';
			else s += 'a';
			cout << s << '\n';
		} else {
			int n = s.size();
			bool done = false;
			cout << s[0];
			for (int i = 1; i < n; ++i) {
				if (done) cout << s[i];
				else if (s[i] == s[i - 1]) {
					if (s[i] == 'a') cout << "ba";
					else cout << 'a' << s[i];
					done = true;
				} else cout << s[i];
			}
			if (!done) {
				if (s[n - 1] == 'a') cout << 'b';
				else cout << 'a';
			}
			cout << '\n';
		}		
	}
}