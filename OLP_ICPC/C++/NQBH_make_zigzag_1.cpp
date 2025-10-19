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
			prefix_max[i] = max(prefix_max[i - 1], a[i]);
			prefix_max[i + 1] = max(prefix_max[i], a[i + 1]);
			if (i & 1) {
				if (a[i] == a[i + 1]) {
					--a[i]; // do op2
					++ans;
				} else if (a[i] > a[i + 1]) {
					if (prefix_max[i + 1] > a[i + 1]) {
						a[i + 1] = prefix_max[i + 1]; // do op1

					}
					else if (prefix_max[i + 1] == a[i]) {
						a[i + 1] = prefix_max[i + 1]; // do op1
						--a[i]; // do op2
						++ans;
					}
				}
			} else { // i even
				if (a[i] == a[i + 1]) {
					if (prefix_max[i] > a[i]) a[i] = prefix_max[i]; // do op1
					else {
						--a[i + 1];
						++ans;
					}
				} else if (a[i] < a[i + 1]) {
					if (prefix_max[i] > a[i + 1]) a[i] = prefix_max[i]; // do op1
					else if (a[i] < prefix_max[i] && prefix_max[i] < a[i + 1]) {
						a[i] = prefix_max[i]; // do op1
						ans += a[i + 1] - a[i] + 1;
						a[i + 1] = a[i] - 1;
					} else if (prefix_max[i] == a[i + 1]) {
						a[i] = prefix_max[i];
						--a[i + 1];
						++ans;
					} else if (prefix_max[i] == a[i]) {
						ans += a[i + 1] - a[i] + 1;
						a[i + 1] = a[i] - 1;
					} 
				}
			}
		}
		cout << ans << '\n';
	}
}
/* still wrong on test:
9
65 85 19 53 21 79 92 29 96
*/