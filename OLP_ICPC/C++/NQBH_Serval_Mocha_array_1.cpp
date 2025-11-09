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
		for (int &x : a) cin >> x;
		bool ok = false;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (gcd(a[i], a[j]) < 3) {
					ok = true;
					break;
				}
		cout << (ok ? "YES\n" : "NO\n"); 
	}
}