#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, H;
		cin >> n >> H;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		if (H <= a[n - 1]) cout << "1\n";
		else if (H <= a[n - 1] + a[n - 2]) cout << "2\n";
		else {
			int ans = H / (a[n - 1] + a[n - 2]) * 2;
			H %= a[n - 1] + a[n - 2];
			if (H > a[n - 1]) ans += 2;
			else if (H) ++ans;
			cout << ans << '\n';
		}
	}
}