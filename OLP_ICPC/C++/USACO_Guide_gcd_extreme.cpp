#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX_N = 1e6;
long long phi[MAX_N + 10]; // phi[i] = how many pairs of numbers <= i are coprime
unordered_map<int, long long> memo;

long long solve(long long n) {
	if (n <= MAX_N) return phi[n];
	if (memo.count(n)) return memo[n];
	long long d = sqrt(n);
	long long ans = 1LL * n * (n + 1) / 2;
	for (int i = 2; n / i > d; ++i) ans -= solve(n / i);
	for (int i = d; i >= 1; --i) ans -= 1LL * (n / i - n / (i + 1)) * solve(i);
	memo[n] = ans;
	return ans;
}

int main() {
	// precompute values of phi as previously shown
	for (int i = 1; i <= MAX_N; ++i) phi[i] = i;
	for (int i = 2; i <= MAX_N; ++i)
		// if i is prime
		if (phi[i] == i) {
			--phi[i];
			for (int j = i + i; j <= MAX_N; j += i) phi[j] = phi[j] / i * (i - 1);
		}
	// prefix sums of phi
	for (int i = 2; i <= MAX_N; ++i) phi[i] += phi[i - 1];
	int n;
	while (cin >> n) {
		if (n == 0) break;
		long long ans = 0;
		for (int d = 1; d <= n; ++d) ans += d * (solve(n / d) - 1);
		cout << ans << '\n';
	}	
}