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
			for (int i = 0; i < n; ++i)
				if (i & 1) cout << "3 ";
				else cout << "-1 ";
			cout << '\n';
		} else {
			for (int i = 0; i < n - 1; ++i)
				if (i & 1) cout << "3 ";
				else cout << "-1 ";
			cout << "2\n";
		}
	}
}