#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, M;
	cin >> n >> M;
	vector<int> a(n), dpmin(M + 1, 1e9), dpmax(M + 1, -1);
	dpmin[0] = 0;
	dpmax[0] = 0;
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	/* too time-consuming
	if (n == 1) {
		if (M % a[0] == 0) {
			int ans = M / a[0];
			cout << ans << ' ' << ans;
		} else cout << "-1 -1";
	} else if (n == 2) {
		if (M % a[1] == 0) ans2 = M / a[1];
		else {
			int lim = M / a[1];
			for (int i = lim; i >= 0; --i)
				if ((M - a[1] * i) % a[0] == 0) {
					ans2 = i + (M - a[1] * i) / a[0];
					break;
				}			
		}
		if (M % a[0] == 0) ans1 = M / a[0];
		else {
			int lim = M / a[0];
			for (int i = lim; i >= 0; --i)
				if ((M - a[0] * i) % a[1] == 0) {
					ans2 = i + (M - a[0] * i) / a[1];
					break;
				}			
		}
		cout << ans1 << ' ' << ans2;
	} else {
		// dp
	}
	*/
	// just extended knapsack
	for (int i = 0; i < n; ++i) {
		for (int j = a[i]; j <= M; ++j) {
			if (dpmin[j - a[i]] != 1e9) dpmin[j] = min(dpmin[j], dpmin[j - a[i]] + 1);
			if (dpmax[j - a[i]] != -1) dpmax[j] = max(dpmax[j], dpmax[j - a[i]] + 1);
		}
	}
	if (dpmin[M] == 1e9 || dpmax[M] == -1) cout << "-1\n";
	else cout << dpmin[M] << ' ' << dpmax[M] << '\n';
}