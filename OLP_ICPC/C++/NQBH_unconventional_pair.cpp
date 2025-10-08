#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int& v : a) cin >> v;
		if (n == 2) cout << abs(a[0] - a[1]) << '\n';
		else {
			int ans = 0;
			sort(a.begin(), a.end());
			for (int i = 0; i <= n - 2; i += 2) ans = max(ans, abs(a[i] - a[i + 1]));
			cout << ans << '\n';
		}
	}
}