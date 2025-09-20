#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;
int phi[MAX_N + 1];

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	if (n > 1) ret.push_back(n);
	return ret;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int phi_totient(int n) {
	int ans = n;
	for (int p = 2; p * p <= n; ++p)
		if (n % p == 0) {
			while (n % p == 0) n /= p;
			ans -= ans / p;
		}
	if (n > 1) ans -= ans / n;
	return ans;
}

// precompute totient of all numbers between 1 & n
void precompute() {
	for (int i = 1; i < MAX_N; ++i) phi[i] = i; // NQBH: why not phi[i] = i - 1?
	for (int i = 1; i < MAX_N; ++i)
		// if i is prime
		if (phi[i] == i)
			for (int j = i; j < MAX_N; j += i) phi[j] -= phi[j] / i;
}

int main() {
	int n;
	cin >> n;
	vector<int> prime_factor = factor(n);
	for (int v : prime_factor) cout << v << " ";
	cout << '\n';
	cout << phi_totient(n);
}