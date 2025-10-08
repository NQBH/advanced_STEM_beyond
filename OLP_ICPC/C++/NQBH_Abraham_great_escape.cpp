#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n == 2) {
			if (k == 0) cout << "YES\nRL\nRL\n";
			else if (k == 1) cout << "YES\nUD\nRL\n";
			else if (k == 2) cout << "YES\nUU\nRL\n";
			else if (k == 3) cout << "NO";
			else if (k == 4) cout << "YES\nUU\nUU\n";
		} else if (n == 3) {
			if (k == 5) cout << "YES\nUUU\nRDR\nULR\n";
		}
	}
}