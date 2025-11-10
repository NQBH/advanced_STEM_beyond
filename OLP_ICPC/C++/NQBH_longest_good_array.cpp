#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		int L = r - l + 1; // transform [l, r] into [1, L]
		int ans = 1;
		while (1 + ans * (ans - 1) / 2 <= L) ++ans;
		cout << (1 + ans * (ans - 1) / 2 == L ? ans : ans - 1) << '\n';
	}
}