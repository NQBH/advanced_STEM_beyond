#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0, odd = 0, even = 0, pair = 0;
		cin >> n;
		vector<int> a(2 * n);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		if (f.size() == 1) {
			if (n & 1) cout << "2\n";
			else cout << "0\n";
			continue;
		}
		for (auto e : f) {
			if (e.second & 1) ++odd;
			else ++even;
			pair += e.second / 2;
		}
		int lower = max(0, n - 2 * pair), upper = n, max_x = min(even, n), best_x = 0;
        for (int x = max_x; x >= 0; --x) {
            int s_low = max(lower, x);
            int s_high = min(upper, x + odd);
            if (s_low > s_high) continue;
            if ((s_low & 1) == (n & 1)) {
                // s_low works
                best_x = x;
                break;
            } else if (s_low + 1 <= s_high) {
                best_x = x;
                break;
            }
        }
		ans = odd + 2 * best_x;
        cout << ans << '\n';
	}
}