#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, ans = 0, n0 = 0;
		bool b = false; // break
		cin >> n >> k;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			if (b) {
				b = false;
				continue;
			}
			if (!a[i]) ++n0;
			else n0 = 0;
			if (n0 == k) {
				++ans;
				n0 = 0;
				b = true;
				continue;
			}			
		}
		cout << ans << '\n';
	}
}