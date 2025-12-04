#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, have0 = 0;
	cin >> n;
	vector<int> h(n);
	for (int &x : h) {
		cin >> x;
		if (!x) ++have0;
	}
	if (!have0) cout << 1;
	else {
		int Hmax = min(h[0], h[n - 1]);
		int ans = n - 1;
		for (int H = 2; H <= Hmax; ++H) {
			bool ok = true;
			int cnt_skip = 0; // skip = position where h[i] < H
			for (int i = 1; i < n; ++i) {
				if (h[i] < H) ++cnt_skip;
				else {
					if (cnt_skip >= H) {
						ok = false;
						break;
					}
					cnt_skip = 0;
				}
			}
			if (!ok) continue;
			else {
				ans = H;
				break;
			}
		}
		cout << ans;
	}
}