// source: [Wu_Wang2016, pp. 7--9]
#include<iostream>
using namespace std;
const int maxp = 2000, n = 10000; // set size of prime array & upper limit of prime numbers
int prime[maxp], total = 0; // init

bool isprime(int k) { // determine whether k is a prime or not
	for (int i = 0; i < total; ++i)
		if (k % prime[i] == 0)
			return false;
	return true;
}

int main() {
	for (int i = 2; i <= n; ++i) // get all primes < 10001
		if (isprime(i))
			prime[total++] = i;
	prime[total] = n + 1;
		int m;
		cin >> m; // input 1st positive integer
		while (m) {
			int ans = 0; // init
			for (int i = 0; m >= prime[i]; ++i) { // enumerate least prime number
				int cnt = 0;

			}
		}
	return 0;
}