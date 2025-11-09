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
		if (n & 1) {
			cout << "1 ";
			for (int i = 2; i < n; i += 2) cout << i + 1 << ' ' << i << ' ';
			cout << '\n';
		} else {
			for (int i = 1; i < n; i += 2) cout << i + 1 << ' ' << i << ' ';
			cout << '\n';
		}
	}
}