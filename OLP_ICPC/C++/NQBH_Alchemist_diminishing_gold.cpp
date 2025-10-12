#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int m = 1e9 + 7;

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
	/*
	long long n, k;
	cin >> n >> k;
	*/

	long long p = 7, q = 4;
	long long inv_q = exp(q, m - 2, m);
	cout << (p * inv_q % m);	
}