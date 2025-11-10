#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, R = 0, ans = 0;
		cin >> n >> k;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			if (a[i] >= k) R += a[i];
			if (a[i] == 0 && R) ++ans, --R;
		}
		cout << ans << '\n';
	}
}