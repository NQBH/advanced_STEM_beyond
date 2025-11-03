#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 1;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		for (int i = 0; i < n; ++i)
			if (a[i] > b[i]) ans += a[i] - b[i];
		cout << ans << '\n';
	}
}