#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n - 1; i += 2)
		if (a[i] != a[i + 1]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}