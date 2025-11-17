#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long xa, ya, xb, yb, xc, yc, ans = 1;
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		xb -= xa;
		xc -= xa;
		yb -= ya;
		yc -= ya;
		if (xb * xc >= 0) ans += min(abs(xb), abs(xc)); // same side left/right
		if (yb * yc >= 0) ans += min(abs(yb), abs(yc)); // same side up/down
		cout << ans << '\n';
	}
}