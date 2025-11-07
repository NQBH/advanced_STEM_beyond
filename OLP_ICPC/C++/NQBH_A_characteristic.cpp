#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, n1 = -1;
		cin >> n >> k;
		for (int i = 0; i <= n; ++i)
			if (i * (i - 1) + (n - i) * (n - i - 1) == 2 * k) {
				n1 = i;
				break;
			}
		if (n1 == -1) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n1; ++i) cout << "-1 ";
			for (int i = 0; i < n - n1; ++i) cout << "1 ";
			cout << '\n';
		}
	}
}