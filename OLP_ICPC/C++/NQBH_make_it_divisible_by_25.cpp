#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 25 == 0) cout << "0\n";
		else { // 2 last digits must be 00, 25, 50, 75
			string s = to_string(n);
			// 00, 50
			int i, n0 = 0, n5 = 0;
			bool ok0 = false, ok5 = false;
			for (i = s.size() - 1; i >= 0; --i)
				if (s[i] == '0') break;
				else ++n0;
			for (int j = i - 1; j >= 0; --j)
				if (s[j] == '0' || s[j] == '5') {
					ok0 = true;
					break;
				} else ++n0;
			// 25, 75
			for (i = s.size() - 1; i >= 0; --i)
				if (s[i] == '5') break;
				else ++n5;
			for (int j = i - 1; j >= 0; --j)
				if (s[j] == '2' || s[j] == '7') {
					ok5 = true;
					break;
				} else ++n5;
			if (!ok0) cout << n5 << '\n';
			else if (!ok5) cout << n0 << '\n';
			else cout << min(n0, n5) << '\n';		}
	}
}