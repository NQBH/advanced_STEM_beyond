#include <iostream>
using namespace std;
#define ll long long

const int MAXN = (1 << 15) + 1;
int n, k;
ll dp[MAXN][16];

int get_bit(int x, int k) { // lấy bit thứ k của số x
	return (x >> k) & 1;
}

int solve(int n, int k) {
	for (int mask = 0; mask < (1 << n); ++mask)
		for (int k = 0; k <= n; ++k) dp[mask][k] = 0;
	dp[0][0] = 1; // base case
	for (int mask = 0; mask < (1 << n); ++mask)
		for (int q = 1; q <= n; ++q) {
			if (get_bit(mask, q - 1)) continue; // check q nằm trong tập hợp (biểu diễn bằng mask)
			for (int p = 0; p <= n; ++p) {
				if (p != 0 && abs(q - p) > k) continue; // check chênh lệch của p & q
				int new_mask = mask | (1 << (q - 1)); // thêm q vào tập hợp
				dp[new_mask][q] += dp[mask][p];
			}
		}
	ll res = 0;
	int full_mask = (1 << n) - 1;
	for (int k = 1; k <= n; ++k) res += dp[full_mask][k];
	return res;
}

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << solve(n, k) << '\n'; 
	}
}
// Verdict: Wrong answer on test 7 on CodeForces.