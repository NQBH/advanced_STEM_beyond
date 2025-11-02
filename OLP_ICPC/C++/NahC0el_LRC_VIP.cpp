#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(a.begin(), a.end());
		if (mn == mx) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i)
			cout << (1 + (a[i] == mx)) << " \n"[i + 1 == n];
	}
}