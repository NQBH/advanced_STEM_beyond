#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1'000'000'000'000LL;

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	if (y == 1) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < x; ) {
		int cur = (k - 1) / (y - 1);
		if (!cur) break;
		int fk = (cur + 1) * (y - 1) + 1;
		int cnt = (fk - k + cur - 1) / cur;
		cnt = min(x - i, cnt);
		k += cnt * cur;
		if (k > INF) {
			cout << "-1\n";
			return;
		}
		i += cnt;
	}
	cout << k << '\n';
}

signed main() {
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
	         chrono::high_resolution_clock::now()
	         - _clock_start).count() << "ms." << endl;
#endif
}