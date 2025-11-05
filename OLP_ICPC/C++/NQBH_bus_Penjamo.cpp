#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, r, rem = 0, ans = 0;
		cin >> n >> r;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x & 1) {
				ans += x - 1;
				++rem;
			} else ans += x;
		}
		r -= ans / 2;
		if (rem <= r) ans += rem;
		else ans += 2 * r - rem;
		cout << ans << '\n';
	}
}