#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	string s;
	cin >> n >> d >> s;
	vector<int> dp(n, 1000); // min num jumps to reach pos i
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			for (int j = max(i - d, 0); j < i; ++j)
				if (s[j] == '1') dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	cout << (dp[n - 1] < 1000 ? dp[n - 1] : -1);
}