#include <iostream>
using namespace std;
#define ll long long

const ll MAXN = (1 << 15) + 1;
ll n, k;
ll dp[MAXN][16];

ll get_bit(ll x, ll k) { // lấy bit thứ k của số x
	return (x >> k) & 1;
}

ll solve(ll n, ll k) {
	for (ll mask = 0; mask < (1 << n); ++mask)
		for (ll k = 0; k <= n; ++k) dp[mask][k] = 0;
	dp[0][0] = 1; // base case
	for (ll mask = 0; mask < (1 << n); ++mask)
		for (ll q = 1; q <= n; ++q) {
			if (get_bit(mask, q - 1)) continue; // check q nằm trong tập hợp (biểu diễn bằng mask)
			for (ll p = 0; p <= n; ++p) {
				if (p != 0 && abs(q - p) > k) continue; // check chênh lệch của p & q
				ll new_mask = mask | (1 << (q - 1)); // thêm q vào tập hợp
				dp[new_mask][q] += dp[mask][p];
			}
		}
	ll res = 0;
	ll full_mask = (1 << n) - 1;
	for (ll k = 1; k <= n; ++k) res += dp[full_mask][k];
	return res;
}

int main() {
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << solve(n, k) << '\n'; 
	}
}