#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int pos1 = 0, posn = 0;
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (!pos1 && a[i] == 1) pos1 = i;
			if (!posn && a[i] == n) posn = i;
		}
		bool left1 = (pos1 < n + 1 - pos1), leftn = (posn < n + 1 - posn);
		int dist1 = min(pos1, n + 1 - pos1), distn = min(posn, n + 1 - posn);
		if (left1 == leftn) cout << max(dist1, distn) << '\n';
		else cout << min({dist1 + distn, max(pos1, posn), n + 1 - min(pos1, posn)}) << '\n';
	}
}