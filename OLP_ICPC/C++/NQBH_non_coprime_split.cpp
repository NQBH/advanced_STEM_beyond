#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool isPrime(int n) { // DPAK's
	if (n < 2) return false;
	if (n == 2 || n == 3 || n == 5) return true;
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/* sieve primes
	vector<bool> is_prime(1e7 + 1, true);
	for (int i = 2; i * i <= 1e7; i++) {
		if (is_prime[i])
			for (int j = i * i; j <= 1e7; j += i)
				is_prime[j] = false;
	}
	*/
	map<int, int> pre_ans; // pre_ans[i] = answer for r = i: [a, r - a]
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		if (r <= 3) {
			cout << -1 << '\n';
			continue;
		}
		if (r > l) {
			if (r & 1) cout << 2 << ' ' << r - 3 << '\n';
			else cout << 2 << ' ' << r - 2 << '\n';
			continue;
		}
		// l = r
		if (pre_ans[r] == -1) {
			cout << -1 << '\n';
			continue;
		} else if (pre_ans[r]) {
			cout << pre_ans[r] << ' ' << r - pre_ans[r] << '\n';
			continue;
		} else { // pre_ans[r] = 0
			if (!(r & 1)) {
				pre_ans[r] = 2;
				cout << 2 << ' ' << r - 2 << '\n';
			} else { // l = r odd
				if (isPrime(r)) cout << -1 << '\n';
				else { // l = r composite
					for (int i = 3; i < r; ++i) {
						if (r % i == 0) {
							pre_ans[r] = i;
							cout << i << ' ' << r - i << '\n';
							break;
						}
					}
				}
			}
		}
	}
}