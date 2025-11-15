#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 1, cnt = 1;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	for (int i = 1; i < n; ++i) {
		if (a[i] >= a[i - 1]) {
			++cnt;
			ans = max(ans, cnt);
		} else cnt = 1;
	}
	cout << ans;
}