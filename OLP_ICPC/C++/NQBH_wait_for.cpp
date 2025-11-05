#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, n_man = 0;
	cin >> n;
	while (n--) {
		char c;
		int a;
		cin >> c >> a;
		if (c == 'B') {
			if (n_man >= a) {
				cout << "NO\n";
				n_man -= a;
			} else {
				cout << "YES\n";
				n_man = 0;
			}
		} else n_man += a;
	}
}