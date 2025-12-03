#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1, INT_MAX), suf(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre[i] = min(pre[i - 1], a[i]);
	}
	for (int i = n; i >= 1; --i) suf[i] = max(suf[i + 1], a[i]);
	for (int i = 1; i <= n; ++i) cout << (a[i] == pre[i] || a[i] == suf[i] ? 1 : 0);
	cout << '\n';
}

int main() {
	int t;
    cin >> t;
    while(t--) solve();
}