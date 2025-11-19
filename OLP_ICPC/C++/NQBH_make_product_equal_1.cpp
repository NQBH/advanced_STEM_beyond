#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, nm1 = 0, n0 = 0;
	long long ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 1) ans += a[i] - 1;
		else if (a[i] <= -1) {
			ans += -1 - a[i];
			++nm1;
		} else if (!a[i]) {
			++ans;
			++n0;
		}
	}
	if ((nm1 & 1) && !n0) ans += 2;
	cout << ans;
}