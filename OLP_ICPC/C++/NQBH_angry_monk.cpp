#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, ans = 0;
		cin >> n >> k;
		vector<int> a(k);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		for (int i = 0; i < k - 1; ++i)
			ans += 2 * a[i] - 1;
		cout << ans << '\n';
	}
}