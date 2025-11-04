#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (n == 1) cout << m * a[0] << '\n';
		else {
			ll ans = 0;
			sort(a.begin(), a.end());
			for (int i = n - 1; i >= 0 && m; --i, --m) ans += 1ll * a[i] * m;
			cout << ans << '\n';
		}		
	}
}