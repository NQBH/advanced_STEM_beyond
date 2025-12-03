#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		string a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; ++i) {
			if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')) ans += 2;
			else if (a[i] == '0' && b[i] == '0') {
				if ((a[i + 1] == '0' && b[i + 1] == '1') || (a[i + 1] == '1' && b[i + 1] == '0')) ++ans;
				else if (a[i + 1] == '1' && b[i + 1] == '1') { // merge
					ans += 2;
					++i;
				}
				else ++ans;
			} else { // a[i] = b[i] = 1
				if (a[i + 1] == '0' && b[i + 1] == '0') { // merge
					ans += 2;
					++i;
				}
			}
		}
		cout << ans << '\n';
	}
}