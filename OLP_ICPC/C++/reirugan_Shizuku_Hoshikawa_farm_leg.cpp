#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	cout << (n & 1 ? 0 : n / 4 + 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}