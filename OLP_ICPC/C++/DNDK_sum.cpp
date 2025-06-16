#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long sum = 0;
	while (abs(n) > 10000)
		cin >> n;
	if (n > 0)
		sum = (n * (n + 1)) / 2;
	else
		sum = (n * (1 - n)) / 2 + 1;
	cout << sum;
	return 0;
}