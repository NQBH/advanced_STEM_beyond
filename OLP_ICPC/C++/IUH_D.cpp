#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, ans = 0;
	cin >> n >> k;
	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; ++i){
		int x, r, q;
		cin >> x >> r >> q;
		a[i] = {q, x, r}; // sort by intelligence faster
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (a[j][0] - a[i][0] > k) break;
			else {
				if (a[i][1] <= a[j][1]) {
					if (a[i][1] + a[i][2] >= a[j][1] && a[i][1] >= a[j][1] - a[j][2]) ++ans;
				} else {
					if (a[j][1] + a[j][2] >= a[i][1] && a[j][1] >= a[i][1] - a[i][2]) ++ans;
				}
			}
		}
	cout << ans;
}