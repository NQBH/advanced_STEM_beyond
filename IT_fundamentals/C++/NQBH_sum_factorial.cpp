#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 0)
		cout << "Error: n must be a positive integer.";
	else {
		long long S = 1, factorial = 1;
		for (int i = 2; i <= n; ++i) {
			factorial *= i;
			S += i * factorial;
		}
		cout << "S! = " << S << '\n';
		if (S == factorial * (n + 1) - 1)
			cout << "S!(" << n << ") = f(" << n << ") = " << S;
		else if (S < factorial * (n + 1) - 1)
			cout << "S!(" << n << ") < f(" << n << ") = " << S;
		else if (S > factorial * (n + 1) - 1)
			cout << "S!(" << n << ") > f(" << n << ") = " << S;
	}
}