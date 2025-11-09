#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n == 1) cout << 3;
	else if (n == 2) cout << 4;
	else if (n & 1) cout << 1;
	else if (n % 3 == 1) cout << 2;
	else if (n % 3 == 2) cout << 1;
	else {
		for (int m = 1; m <= 1000; ++m) {
			bool ok = 0;
			int a = n * m + 1;
			for (int i = 2; i <= n * m; ++i)
				if (a % i == 0) {
					ok = 1;
					break;
				}
			if (ok) {
				cout << m;
				break;
			}
		}
	}
}