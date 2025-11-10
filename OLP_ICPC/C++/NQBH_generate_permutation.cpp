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
		if (n == 1) cout << "1\n";
		else if (n & 1) {
			for (int i = 1; i <= n / 2; ++i) cout << i << ' ';
			cout << n << ' ';
			for (int i = n - 1; i > n / 2; --i) cout << i << ' ';
		} else cout << "-1\n";
	}
}