#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int mn = 1, mx = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < a[mn]) mn = i;
		if (a[i] > a[mx]) mx = i;
	}
	string t;
	cin >> t;
	t = " " + t;
	if (t[1] == '1' || t[n] == '1') {
		cout << "-1\n";
		return;
	}
	if (t[mn] == '1' || t[mx] == '1') {
		cout << "-1\n";
		return;
	}
	cout << 5 << "\n";
    cout << 1 << " " << mn << "\n";
    cout << 1 << " " << mx << "\n";
    cout << mn << " " << n << "\n";
    cout << mx << " " << n << "\n";
    cout << min(mn, mx) << " " << max(mn, mx) << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}