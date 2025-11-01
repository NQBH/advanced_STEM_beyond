#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int m, a, b, c, ans = 0, left = 0;
		cin >> m >> a >> b >> c;
		if (a > m) ans += m;
		else ans += a, left += m - a;
		if (b > m) ans += m;
		else ans += b, left += m - b;
		if (c > left) ans += left;
		else ans += c;
		cout << ans << '\n';
	}
}