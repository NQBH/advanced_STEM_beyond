#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_case_num;
	cin >> test_case_num;

	for (int t = 0; t < test_case_num; t++) {
		int n;
		cin >> n;

		vector<int> bosses(n);
		for (int j = 0; j < n; j++) { cin >> bosses[j]; }

		/*
		 * dp[i][j] = the min amount of skip points
		 * on turn i (your turn is 0), on the jth boss.
		 * (1e9 to prevent overflow)
		 */
		vector<vector<int>> dp(2, vector<int>(n + 1, 1e9));

		/*
		 * base case:
		 * your friend uses zero skip points before fighting any bosses.
		 */
		dp[1][0] = 0;

		for (int j = 0; j < n; j++) {
			// the opposite player switches on the previous move.
			dp[0][j + 1] = min(dp[0][j + 1], dp[1][j] + bosses[j]);
			dp[1][j + 1] = min(dp[1][j + 1], dp[0][j]);

			// the opposite player switches from the previous two moves.
			if (j + 2 <= n) {
				dp[0][j + 2] = min(dp[0][j + 2], dp[1][j] + bosses[j] + bosses[j + 1]);
				dp[1][j + 2] = min(dp[1][j + 2], dp[0][j]);
			}
		}
		cout << min(dp[0][n], dp[1][n]) << endl;
	}
}