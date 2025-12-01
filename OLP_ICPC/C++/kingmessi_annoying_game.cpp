#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	k &= 1; // it can be reduced as 0/1 move game
	vector<long long> L(n); // maximum sum nonempty subarray ending at each position
	for (int i = 0; i < n; ++i) L[i] = (i && L[i - 1] > 0 ? L[i - 1] : 0ll) + a[i];
	vector<long long> R(n); // maximum sum nonempty subarray starting at each position
	for (int i = n - 1; i >= 0; --i) R[i] = (i + 1 < n && R[i + 1] > 0 ? R[i + 1] : 0ll) + a[i];
	if (!k) {
		long long ans = *max_element(L.begin(), L.end());
		cout << ans << '\n';
	} else {
		long long ans = LONG_MIN;
		for (int i = 0; i < n; ++i) ans = max(ans, L[i] + R[i] - a[i] + b[i]);
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}