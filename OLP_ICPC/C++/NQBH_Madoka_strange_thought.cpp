#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else if (n == 2) cout << "4\n";
		else if (n == 3) cout << "7\n";
		else {
			long long ans = n; // pair (n, n)
			ans += (n / 2) * 2; // pair (d, 2d), (2d, d)
			ans += (n / 3) * 2; // pair (d, 3d), (3d, d)
			cout << ans << '\n';
		}
	}
}