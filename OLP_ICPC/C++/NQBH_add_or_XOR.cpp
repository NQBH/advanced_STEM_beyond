#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if (a == b) cout << "0\n";
		else if (a < b) {
			if (x <= y) cout << (b - a) * x << '\n';
			else {
				int diff = b - a;
				if (a & 1) cout << diff / 2 * y + (diff - diff / 2) * x << '\n';
				else cout << diff / 2 * x + (diff - diff / 2) * y << '\n';
			}
		} else if (a - b == 1 && a & 1) cout << y << '\n';
		else cout << "-1\n";
	}
}