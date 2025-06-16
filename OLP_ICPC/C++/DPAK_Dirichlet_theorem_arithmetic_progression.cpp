/*
Source: ACM Japan 2006, Domestic.
IDs for online judges: POJ 3006.
Status: Accepted.
*/
#include <iostream>
#include <vector>

using namespace std;

int maxPrimeNumber = 1000000;
vector<bool> prime(maxPrimeNumber + 1, true);

void sieve() {
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= maxPrimeNumber; ++i)
		if (prime[i])
			for (int j = i * i; j <= maxPrimeNumber; j += i)
				prime[j] = false;
}

int main() {
	sieve();
	int a, d, n;
	while (cin >> a && a != 0 && cin >> d >> n) {
		int number = 0;
		int index = 0;
		int result = 0;
		while (number < n) {
			if (prime[a + index * d] == true) {
				++number;
				result = a + index * d;
			}
			++index;
		}
		cout << result << '\n';
	}
}