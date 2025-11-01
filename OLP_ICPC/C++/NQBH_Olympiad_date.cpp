#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		map<int, int> f;
		bool ok = false;
		for (i = 0; i < n; ++i) {
			if (a[i] == 0) ++f[0];
			else if (a[i] == 1) ++f[1];
			else if (a[i] == 2) ++f[2];
			else if (a[i] == 3) ++f[3];
			else if (a[i] == 5) ++f[5];
			if (f[0] >=3 && f[1] >= 1 && f[2] >= 2 && f[3] >= 1 && f[5] >= 1) {
				ok = true;
				break;
			}
		}
		if (ok) cout << i + 1 << '\n';
		else cout << "0\n";
	}
}