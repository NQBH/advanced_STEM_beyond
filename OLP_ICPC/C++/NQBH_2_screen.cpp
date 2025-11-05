#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		int l = min(s.size(), t.size());
		int i;
		for (i = 0; i < l; ++i)
			if (s[i] != t[i]) break;
		if (i == 0) cout << s.size() + t.size() << '\n';
		else cout << s.size() + t.size() - i + 1 << '\n';
	}
}