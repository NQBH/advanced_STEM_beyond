#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k, q;
		cin >> k >> q;
		vector<int> a(k), n(q);
		for (int &x : a) cin >> x;
		for (int &x : n) cin >> x;
		for (int i = 0; i < q; ++i) cout << min(n[i], a[0] - 1) << ' ';
		cout << '\n';
	}
}