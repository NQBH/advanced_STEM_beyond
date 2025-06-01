#include <iostream>
#include <climits>
using namespace std;

unsigned long long factorial(int n) {
	unsigned long long res = 1;
	for (int i = 2; i <= n; ++i) {
		if (res > ULLONG_MAX / i) {
			cout << "Overflow tại n = " << i << " khi tính giai thừa.\n";
			return 0;
		}
		res *= i;
	}
	return res;
}

unsigned long long permutation(int n, int k) {
	unsigned long long a = factorial(n);
	unsigned long long b = factorial(n - k);
	return (b == 0) ? 0 : a / b;
}

unsigned long long combination(int n, int k) {
	unsigned long long a = factorial(n);
	unsigned long long b = factorial(k);
	unsigned long long c = factorial(n - k);
	return (b == 0 || c == 0) ? 0 : a / (b * c);
}

unsigned long long catalan(int n) {
	unsigned long long a = factorial(2 * n);
	unsigned long long b = factorial(n + 1);
	unsigned long long c = factorial(n);
	return (b == 0 || c == 0) ? 0 : a / (b * c);
}

int main() {
	int n, k;
	cout << "Nhap n (n > 0): ";
	cin >> n;
	cout << "Nhap k (0 <= k <= n): ";
	cin >> k;

	cout << "\n=== Ket qua ===\n";

	unsigned long long fn = factorial(n);
	if (fn != 0) cout << "Pn = " << fn << endl;

	unsigned long long Ank = permutation(n, k);
	if (Ank != 0) cout << "A^k_n = " << Ank << endl;

	unsigned long long Cnk = combination(n, k);
	if (Cnk != 0) cout << "C^k_n = " << Cnk << endl;

	unsigned long long Catn = catalan(n);
	if (Catn != 0) cout << "Catalan(n) = " << Catn << endl;
	return 0;
}