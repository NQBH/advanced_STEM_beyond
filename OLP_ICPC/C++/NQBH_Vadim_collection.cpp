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
		map<int, int> f;
		for (int i = 0; i < 10; ++i)
			++f[s[i] - '0'];
		cout << 9;
		--f[9];
		// for (auto [a, cnt] : f) cout << a << ',' << cnt << ' ';
		for (int i = 1; i < 10; ++i) {
			int a = 10 - i - 1;
			if (f[a]) {
				cout << a;
				--f[a];
			} else {
				while (!f[a] && a <= 9) ++a;
				if (a == 10) {
					cout << 9;
					--f[9];
				} else cout << a;
				--f[a];
			}
		}
		cout << '\n';
	}
}