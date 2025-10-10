#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		vector<ll> a(n + 1);
		vector<bool> jumpable_into(n + 1, false);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) {
			if (jumpable_into[i]) continue;
			int sum = a[i], j = i;
			while (j + a[j] <= n) {
				j += a[j];
				jumpable_into[j] = true;
				sum += a[j];
			}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
}