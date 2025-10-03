#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int m = 998244353; // F_44 = 701408733 < m < F_45 = 1134903170

long long exp(long long x, long long n, long long m) {
	x %= m;
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) res = res * x % m;
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
	long long n;
	int k;
	cin >> n >> k;
	if (k == 1) { // sum_{i=1}^n F_i = F_{n+2} - 1
		long long a = 1, b = 1; // F_1 & F_2
		long long c;
		for (long long i = 3; i <= n + 2; ++i) {
			c = a + b; // c = F[i]
			if (i > 44) c %= m;
			a = b;
			b = c;
		}
		int ans = c - 1 % m; // F[n + 2 ] - 1 mod m
		cout << ans;
	}
	else if (k == 2) { // sum_{i=1}^{n+1} F_i^2 = F_nF_{n+1}
		long long a = 1, b = 1; // F_1 & F_2
		long long c;
		for (long long i = 3; i <= n + 1; ++i) {
			c = a + b; // c = F[i]
			if (i > 44) c %= m;
			a = b;
			b = c;
		}
		int ans = (a * c) % m; // F_nF_{n+1}
		cout << ans;
	}
	else { // k >= 3
		long long a = 1, b = 1; // F_1 & F_2
		long long c;
		long long ans = 2; // F_1^k = 1
		for (long long i = 3; i <= n; ++i) {
			c = a + b; // c = F_i % m
			if (i > 44) c %= m;
			// compute c^k mod m = F_i^k mod m
			ans = (ans + exp(c, k, m)) % m;
			a = b;
			b = c;
		}
		cout << ans;
	}
}
// AC: 12/122 VNOJ