#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	if (m == n)
		cout << 1;
	else {
		if (n % m == 0)
			cout << n / m;
		else if (m % n == 0)
			cout << m / n;
		else { // main case: n is not divisible by m
			if (m > n) { // after this: m < n
				int tmp = m;
				m = n;
				n = tmp;
			}

			vector<bool> prime(n + 1, true);
			for (int p = 2; p * p <= n; p++)
				if (prime[p] == true)
					for (int i = p * p; i <= n; i += p)
						prime[i] = false;

			vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e3)); // dp[m][n] = dp[n][m]: the minimum number of squares after cutting a rectangle m x n

			// base cases dp[m][1] = m, dp[1][n] = n
			for (int i = 1; i <= n; ++i) {
				dp[i][1] = dp[1][i] = i;
				dp[i][2] = dp[2][i] = i / 2 + 2 * (i % 2);
			}

			for (int i = 3; i <= n; ++i) {
				dp[i][i] = 1;
				for (int j = i + 1; j <= n; ++j) {
					if (j % i == 0)
						dp[i][j] = dp[j][i] = j / i;
					else {
						dp[i][j] = dp[j % i][i] + j / i; // init: take j / i squares of size i * i & cut the remaining rectangle i * (j % i)

						/*
						if (prime[j] == false)
							for (int d = 1; d <= j / 2; ++d)
								if (j % d == 0 && d < i) {
									// dp[i][j] = min(dp[i][j], (j / d) * (i / d) + dp[i % d][j]);
									dp[i][j] = min(dp[i][j], dp[i - d][j] + dp[d][j]);
								}
						dp[j][i] = dp[i][j]; // symmetrization
						
						for (int d = 1; d <= i / 2; ++d) {
							if (i % d == 0 && d < j) {
								dp[i][j] = min(dp[i][j], dp[i][j - d] + dp[i][d]);
							}
						}*/

						for (int d = 1; d <= i / 2; ++d)
							dp[i][j] = min(dp[i][j], dp[i - d][j] + dp[d][j]);
						dp[j][i] = dp[i][j]; // symmetrization
						for (int d = 1; d <= j / 2; ++d)
							dp[i][j] = min(dp[i][j], dp[i][j - d] + dp[i][d]);
						dp[j][i] = dp[i][j]; // symmetrization
					}
				}
			}

			/*
			if (prime[m] == true)
				dp[m][n] = min(dp[m][n], dp[n % m][m] + n / m);
			else if (prime[n] == true)
				dp[m][n] = min(dp[m][n], dp[m][n % m] + n / m); // take 1 square m x m & compute dp[m][n - m]
			else { // both m & n is composite
				for (int d = n / 2; d >= 2; --d) { // index d in Ư(n) only use if n is composite
					if (n % d == 0 && d < m) {
						dp[m][n] = dp[n][m] = min(dp[m][n], dp[m - d][n] + dp[d][n]);
					}
				}

				for (int d = m / 2; d >= 2; --d) { // index d in Ư(n) only use if n is composite
					if (m % d == 0 && d < n) {
						dp[m][n] = dp[n][m] = min(dp[m][n], dp[m][n - d] + dp[m][d]);
					}
				}

			}
			*/





/*
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j)
					cout << dp[i][j] << " ";
				cout << "\n";
			}
*/

			cout << dp[m][n];

		}
	}
}