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
		vector<int> a(n);
		bool hv1 = 0;
		for (int &x : a) {
			cin >> x;
			if (x == 1) hv1 = 1;
		}
		if (hv1) {
			cout << "YES\n";
			continue;
		}
		sort(a.begin(), a.end()); // faster: 171 ms -> 140 ms
		bool ok = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (gcd(a[i], a[j]) < 3) {
					ok = 1;
					break;
				}
		cout << (ok ? "YES\n" : "NO\n"); 
	}
}