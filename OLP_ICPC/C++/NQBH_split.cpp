#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), f(n + 1, 0), g(n + 1, 0);
		for (int& x : a) {
			cin >> x;
			++f[x];
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i)
			if (f[i] % k) ok = false;
		if (!ok) cout << 0 << '\n';
		else {
			int ans = n; // all subarray consisting of 1 element are awesome
			for (int i = 1; i <= n; ++i)
				f[i] %= k; // maximum number of i in [l, r] 
			for (int l = 0; l < n; --g[a[l++]]) {
				int r = l + 1;
				while (g[a[r]] <= f[a[n]]) {
					++r;
				}
			}
			cout << ans << '\n';
		}		
	}
}