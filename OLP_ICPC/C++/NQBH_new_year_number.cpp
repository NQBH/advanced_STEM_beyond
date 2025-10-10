#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		bool yes = false;
		for (int i = 1; i <= (n - 2021) / 2020 + 1; ++i) {
			if ((n - 2020 * i) % 2021 == 0) cout << "YES\n";
			yes = true;
			break;
		}
		if (!yes) cout << "NO\n";
	}
}