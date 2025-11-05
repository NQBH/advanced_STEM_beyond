#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == 1 || k > n) cout << n << '\n';
		else if (k == n) cout << "1\n";
		else if (k == 2) cout << __builtin_popcount(n) << '\n';
		else {
			int ans = 0;
			while (n) {
				ans += n % k;
				n /= k;
			}
			cout << ans << '\n';			
		}		
	}
}