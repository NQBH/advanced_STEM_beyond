#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k) {
	if (n == 3 && k == 2) return 1;
	if (n == 1) return 1;

	if (k <= n / 2) {
		return (2 * k);
	}

	long long new_n = n / 2;
	long long new_k = k - (n + 1) / 2;

	long long res = solve(new_n, new_k);

	if (n % 2 == 0) {
		return 2 * res - 1;
	} else {
		return 2 * res + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	long long n, k;
	while (q--) {
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
}