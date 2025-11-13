#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a ^ b ^ c) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}