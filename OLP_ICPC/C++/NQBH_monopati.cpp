#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(2 * n);
		for (int &x : a) cin >> x;
		vector<int> dpl(2 * n, 0), dpr(2 * n, 0);
		dpl[0] = a[0], dpr[0] = a[0];
		for (int i = 1; i < n; ++i) {
			dpl[i] = min(dpl[i - 1], a[i]);
			dpr[i] = max(dpr[i - 1], a[i]);
		}
		dpl[n] = min(a[n], dpl[0]);
		dpr[n] = max(a[n], dpr[0]);
		for (int i = n + 1; i < 2 * n; ++i) {
			dpl[i] = max(a[i], min({dpl[i - 1], dpl[i - n]}));
			dpr[i] = max(a[i], min({dpr[i - 1], dpr[i - n]}));
		}
		cout << "l = " << dpl[2 * n - 1] << '\n';
		cout << "r = " << dpr[2 * n - 1] << '\n';
		
		cout << dpl[2 * n - 1] * (2 * n - dpr[2 * n - 1] + 1) << '\n';
	}
}