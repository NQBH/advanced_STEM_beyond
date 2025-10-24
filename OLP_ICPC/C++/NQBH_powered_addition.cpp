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
		vector<int> a(n + 1, -1e9 - 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] < a[i - 1]) {
				int t = __lg(a[i - 1] - a[i]) + 1;
				a[i] = a[i - 1];
				ans = max(ans, t);				
			}
		}
		cout << ans << '\n';
	}
}