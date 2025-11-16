#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long n, a, b;
		cin >> n >> a >> b;
		long long ans = n * a;
		if (a >= b) cout << ans << '\n';
		else {
			for (int k = 1; k <= min(n, b); ++k)
				ans = max(ans, b * k - (k - 1) * k / 2 + (n - k) * a);
			cout << ans << '\n';
		}
	}
}