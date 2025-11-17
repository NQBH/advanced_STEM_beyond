#include <bits/stdc++.h>
using namespace std;
const int m = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		if (n == 1) cout << "0\n";
		else {
			long long ans = n * (n - 1);
			for (int i = 2; i <= n; ++i) {
				ans *= i;
				ans %= m;
			}
			cout << ans << '\n';
		}
	}
}