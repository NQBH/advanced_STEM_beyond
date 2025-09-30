#include <iostream>
#include <vector>
using namespace std;

const int p = 1e9 + 7;

/** @return nCk mod p using naive recursion */
int binomial(int n, int k, int p) {
	if (k == 0 || k == n) { return 1; }
	return (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p)) % p;
}

/** @return nCk mod p using dynamic programming */
int binomial_DP(int n, int k, int p) {	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // dp[i][j] stores iCj
	// base cases
	for (int i = 0; i <= n; ++i) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		if (i <= k) dp[i][i] = 1;
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= min(i, k); ++j)
			if (i != j) // skips over the base cases
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p; // uses the recurrence relation
	return dp[n][k]; // returns nCk modulo p
}

const int MAXN = 1e6;
long long fac[MAXN + 1], inv[MAXN + 1];

/** @return x^n modulo m in O(log p) time. */
long long exp(long long x, long long n, long long m) {
	x %= m; // note: m * m must be < 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) res = res * x % m;
		x = x * x % m;
		n /= 2;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; ++i) fac[i] = fac[i - 1] * i % p;
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; --i) inv[i - 1] = inv[i] * i % p;
}

/** @return nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << choose(n, k, p) << " " << binomial(n, k, p) << " " << binomial_DP(n, k, p) << '\n';
}
// wrong choose function