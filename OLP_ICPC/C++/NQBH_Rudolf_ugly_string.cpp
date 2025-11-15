#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		string s;
		cin >> n >> s;
		s += "  ";
		for (int i = 0; i < s.size() - 3; ++i) {
			if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
				if (s[i + 3] == 'i' && s[i + 4] == 'e') {
					++ans; // del p only
					i += 4;
				} else {
					++ans; // del a
					i += 2;
				}
			}
			if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
				++ans; // del i
				i += 2;
			}
		}
		cout << ans << '\n';
	}
}