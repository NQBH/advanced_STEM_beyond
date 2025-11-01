#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int ans = 2 * (accumulate(x.begin() + 1, x.end(), 0) + m + accumulate(y.begin() + 1, y.end(), 0) + m);
    // int ans = 2 * (accumulate(x.begin(), x.end(), 0) + m - x[0] + accumulate(y.begin(), y.end(), 0) + m - y[0]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}