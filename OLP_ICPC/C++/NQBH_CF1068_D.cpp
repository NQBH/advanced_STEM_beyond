#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		int max_j = (k > 65) ? 65 : (int)k;
		// dp[i][j][carry], i: curr bit, j: bit 1, carry: carry to next pos: dp: min popcount of n + X for bits processed
		vector<vector<vector<int>>> dp(64, vector<vector<int>>(max_j + 1, vector<int>(2, 1e9)));
		dp[0][0][0] = 0;
		for (int i = 0; i < 63; ++i) {
			int n_bit = (n >> i) & 1;
			for (int j = 0; j <= max_j; ++j) {
				for (int carry = 0; carry <= 1; ++carry) {
					if (dp[i][j][carry] == 1e9) continue;
					for (int x_bit = 0; x_bit <= 1; ++x_bit) {
						if (j + x_bit > max_j) continue; // exceed k
						int sum = n_bit + x_bit + carry, res_bit = sum % 2, new_carry = sum / 2;
						int next_pop = dp[i][j][carry] + res_bit;
						// prune if popcount is already worse than best case
						if (next_pop < dp[i + 1][j + x_bit][new_carry]) dp[i + 1][j + x_bit][new_carry] = next_pop;
					}
				}
			}
		}
		int min_last_pop = 1e9;
		for (int j = 0; j <= max_j; ++j) {
			if (dp[63][j][0] != 1e9) min_last_pop = min(min_last_pop, dp[63][j][0]); // carry = 0
			if (dp[63][j][1] != 1e9) min_last_pop = min(min_last_pop, dp[63][j][1] + 1);
		}
		// total score = k + popcount(n) - popcount(n_last)
		cout << k + __builtin_popcountll(n) - min_last_pop << '\n';
	}
}