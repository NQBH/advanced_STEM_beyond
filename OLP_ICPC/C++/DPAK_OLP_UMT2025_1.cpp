#include <bits/stdc++.h>
#define int long long
using namespace std;
int C(int n) {
	return n * (n - 1) / 2;
}

signed main() {
	int n; cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		int l = i + 1, r = n;
		int temp = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[mid] - a[i] <= 2) {
				temp = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (temp == -1) {
			continue;
		}
		int total = temp - i;
		ans += C(total);
	}
	cout << ans;
}