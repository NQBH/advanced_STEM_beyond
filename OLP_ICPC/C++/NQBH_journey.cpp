#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		int ans = 3 * (n / (a + b + c));
		n %= a + b + c;
		if (n > a + b) ans += 3;
		else if (n > a) ans += 2;
		else if (n) ans += 1;
		cout << ans << '\n';
	}
}