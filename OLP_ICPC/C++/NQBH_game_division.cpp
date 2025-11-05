#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, i;
		cin >> n >> k;
		vector<int> a(n);
		map<int, int> f, idx;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			int r = a[i] % k;
			++f[r];
			if (!idx[r]) idx[r] = i + 1;
		}
		bool ok = false;
		for (i = 0; i < k; ++i)
			if (f[i] == 1) {
				ok = true;
				break;
			}
		if (ok) cout << "YES\n" << idx[i] << '\n';
		else cout << "NO\n";		
	}
}