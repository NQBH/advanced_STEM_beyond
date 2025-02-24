// author: Dang Phuc An Khang
#include <bits/stdc++.h>
using namespace std;

int maxPrimeNumber = 31622;
vector<bool> primeCheck(maxPrimeNumber + 1, true);
vector<int> primeList;

void sieve() {
	primeCheck[0] = primeCheck[1] = false;
	for (int i = 2; i * i <= maxPrimeNumber; i++)
		if (primeCheck[i])
			for (int j = i * i; j <= maxPrimeNumber; j += i)
				primeCheck[j] = false;
	for (int i = 2; i <= maxPrimeNumber; i++)
		if (primeCheck[i])
			primeList.push_back(i);
}

int main() {
	sieve();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n <= 1) {
			cout << 1 << endl;
			continue;
		}
		bool checkPrimeFactor = false;
		int ans = n, N = n;

		for (int p : primeList) {
			if (n % p == 0) {
				if (checkPrimeFactor == true) {
					ans = 1;
					break;
				}
				while (n % p == 0) {
					checkPrimeFactor = true;
					n /= p;
					ans = p;
				}
			}
		}
		if (checkPrimeFactor == false && n > 1) ans = N;
		cout << ans << endl;
	}
	return 0;
}