#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k & 1) {
			for (int i = 1; i < n; ++i) cout << n << ' ';
			cout << n - 1 << '\n';
		} else {
			for (int i = 1; i < n - 1; ++i) cout << n - 1 << ' ';
			cout << n << ' ' << n - 1 << '\n';
		}
	}
}