#include <bits/stdc++.h>
using namespace std;

int a[55], b[55];

void solve() {
	int n;
	cin >> n;
	set<int> sa, sb;
	for (int i = 1; i <= n; i++) cin >> a[i], sa.insert(a[i]);
	for (int i = 1; i <= n; i++) cin >> b[i], sb.insert(b[i]);
	if (sa.size() + sb.size() < 4) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}