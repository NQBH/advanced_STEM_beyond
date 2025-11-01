#include<bits/stdc++.h>
using namespace std;

void solve() {
	int k;
	cin >> k;
	if (k % 3 == 1) cout << "Yes\n";
	else cout << "No\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}