#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x = 0, y = 0;
		string s;
		cin >> n >> s;
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'U') ++y;
			else if (s[i] == 'D') --y;
			else if (s[i] == 'L') --x;
			else ++x;
			if (x == 1 && y == 1) {
				ok = true;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}