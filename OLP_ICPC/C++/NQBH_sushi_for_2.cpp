#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	vector<int> t(n);
	for (int &x : t) cin >> x;
	int l1 = 0, l2 = 0;
	if (t[0] == 1) ++l1;
	else ++l2;
	for (int i = 1; i < n; ++i) {
		if (t[i] == t[i - 1]) {
			if (t[i] == 1) ++l1;
			else ++l2;
		} else {
			ans = max(ans, 2 * min(l1, l2));
			if (t[i] == 1) l1 = 1;
			else l2 = 1;
		}
	}
	ans = max(ans, 2 * min(l1, l2));
	cout << ans;
}