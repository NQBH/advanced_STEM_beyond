#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, w, l, h;
		cin >> n >> m;
		vector<int> f(n + 1, 0);
		f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];
		while (m--) {
			bool ok = true;
			cin >> w >> l >> h;
			if (min(w, l) < f[n]) {
				ok = false;
				break;
			} else {
				w_curr = w;
				for (int i = n; i >= 1; --i) {
				if (min(w, l) < f[i]) {
					ok = false;
					break;
				}
			}
			}
			
			if (!ok) cout << 0;
			
		}

		
	}
}