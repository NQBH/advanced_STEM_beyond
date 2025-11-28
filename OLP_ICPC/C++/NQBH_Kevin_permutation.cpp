#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == 1) {
			for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
		} else {
			vector<int> p(n + 1, 0);
			int a = 1, pos = k;
			while (pos < n) {
				p[pos] = a++;
				pos += k;
				if (pos >= n) p[n] = a++;
			}			
			for (int i = 1; i <= n; ++i)
				if (!p[i]) p[i] = a++;
			for (int i = 1; i <= n; ++i) cout << p[i] << " \n"[i == n];
		}
	}
}