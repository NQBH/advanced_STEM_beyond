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
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i < n; ++i) {
			prefix_max[i] = max(prefix_max[i - 1], a[i]); // default prefix max
			if (i & 1) {
				if (a[i] == a[i + 1]) {
					if (prefix_max[i] > a[i]) a[i + 1] = prefix_max[i]; // do oper 1
					else { // do oper 2
						--a[i];
						++ans;
					}
				} else if (a[i] > a[i + 1]) {
					if (prefix_max[i] > a[i]) a[i + 1] = prefix_max[i]; // do oper 1
					else if (prefix_max[i] == a[i]) {
						a[i + 1] = prefix_max[i]; // do oper 1
						--a[i]; // do oper 2
						++ans;
					}
					else { // do oper 2
						ans += a[i] - a[i + 1] + 1;
						a[i] = a[i + 1] - 1;
					}
				}
			} else { // i even
				if (a[i] == a[i + 1]) { // cant do oper 1, must do oper 2
					--a[i + 1];
					++ans;
				} else if (a[i] < a[i + 1]) {
					a[i + 1] = prefix_max[i]; // do oper 1 // new line
					ans += a[i + 1] - a[i] + 1;
					a[i + 1] = a[i] - 1;
				}
				prefix_max[i + 1] = prefix_max[i];
			}
		}
		cout << ans << '\n';
	}
}