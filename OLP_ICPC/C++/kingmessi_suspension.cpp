#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, y, r;
	cin >> n >> y >> r;
	cout << min(n, r + y / 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}