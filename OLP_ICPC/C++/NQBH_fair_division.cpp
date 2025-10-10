#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a, sum = 0, num1 = 0, num2 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			if (a == 1) ++num1;
			else ++num2;
			sum += a;
		}
		if (num1 % 2 || sum % 2 || (num2 % 2 && num1 == 0)) cout << "NO\n";
		else cout << "YES\n";
	}
}