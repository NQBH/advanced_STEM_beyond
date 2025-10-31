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
		vector<int> a(n + 1);
		vector<int> cnt(n + 1, 0);
		set<pair<int, int>> b;
		for (int &x : a) {
			cin >> x;
			++cnt[x];
		}
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		bool nonincreasing = true;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] < a[i + 1]) {
				nonincreasing = false;
				break;
			}
		if (nonincreasing) {
			cout << "0\n";
			continue;
		}
		vector<int> dp(n + 2, 0);
        dp[0] = 0;
        dp[1] = cnt[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i]);
        }
        cout << n - dp[n] << "\n";		
	}
}