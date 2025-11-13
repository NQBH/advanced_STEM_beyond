#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
	int cnt[3] = {};
	for (int i = 0; i < 9; ++i) {
		char c;
		cin >> c;
		if (c != '?') ++cnt[c - 'A'];
	}
	for (int i = 0; i < 3; ++i)
		if (cnt[i] < 3) cout << (char)('A' + i) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}