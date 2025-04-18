#include <iostream>
using namespace std;
long fib(long i) {
	if (i == 1 || i == 2)
		return 1;
	else
		return fib(i - 1) + fib(i - 2);
}

int main() {
	long n, i;
	cin >> n;
	cout << "Fibonacci sequence of length " << n << ": ";
	for (i = 1; i <= n; ++i)
		cout << fib(i) << " ";
}