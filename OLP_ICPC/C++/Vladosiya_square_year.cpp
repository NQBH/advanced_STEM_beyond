#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int sq = ceil(sqrt(n));
	if (sq * sq == n) cout << 0 << ' ' << sq << "\n";
	else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}