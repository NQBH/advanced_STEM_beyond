#include <iostream>
#include <cmath>
using namespace std;

bool check(long long n) {
	long long x = n * n + 1, X = x;
	long long y = 2 * n + sqrtl(2 * n);
	for (long long i = 2; i * i <= X; ++i)
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			if (i > y) return true;
		}
	if (x > 1 and x > y) return true;
	return false;
}

int main() {
	long long a, b;
	cin >> a >> b;
	long long count = 0;
	for (long long i = a; i <= b; ++i)
		if (check(i)) ++count;
	cout << count;
}