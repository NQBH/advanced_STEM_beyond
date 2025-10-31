#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int r0, x, d, n, ans = 0;
		cin >> r0 >> x >> d >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				r0 = max(r0 - d, 0);
				++ans;
			} else {
				if (r0 < x) {
					++ans;
					r0 = max(r0 - d, 0);
				}
			}
		}
		cout << ans << '\n';		
	}
}