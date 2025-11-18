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
		int g = a[0];
		for (int i = 1; i < n; ++i) g = gcd(g, a[i]);
		if (g == 1) cout << "0\n";
		else if (gcd(g, n) == 1) cout << "1\n";
		else if (gcd(g, n - 1) == 1) cout << "2\n";
		else cout << "3\n";
	}
}