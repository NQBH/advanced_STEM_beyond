#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n + 1), prefix_max(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			prefix_max[i] = max(prefix_max[i - 1], a[i]);
			if (i % 2 == 0) a[i] = prefix_max[i]; // do op1 to all even-indexed values
		}
		for (int i = 1; i <= n; i += 2) {
			if (i == 1) ans += max(0, a[1] - a[2] + 1);
			else if (i == n) ans += max(0, a[n] - a[n - 1] + 1);
			else ans += max(0, a[i] - min(a[i - 1], a[i + 1]) + 1);
		}
		cout << ans << '\n';
	}
}