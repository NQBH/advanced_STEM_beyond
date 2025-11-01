#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n < 3) cout << n + 1 << '\n';
		else if (n < 15) cout << "3\n";
		else {
			int r = n % 15;
			if (r == 0) cout << 3 * (n / 15) + 1 << '\n';
			else if (r == 1) cout << 3 * (n / 15) + 2 << '\n';
			else if (r == 2) cout << 3 * (n / 15) + 3 << '\n';
			else cout << 3 * (n / 15 + 1) << '\n';
		}
	}
}