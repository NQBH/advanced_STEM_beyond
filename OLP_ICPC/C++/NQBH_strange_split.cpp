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
		if (a[0] == a[n - 1]) cout << "NO\n";
		else {
			cout << "YES\nBR";
			for (int i = 2; i < n; ++i) cout << 'B';
			cout << '\n';
		}
	}
}