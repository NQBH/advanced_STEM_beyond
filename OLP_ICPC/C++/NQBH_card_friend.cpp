#include <iostream>
using namespace std;

int main() {
	int t, w, h, n;
	cin >> t;
	while (t--) {
		cin >> w >> h >> n;
		if (n == 1) {
			cout << "YES\n";
			continue;
		}
		if (w % 2 && h % 2) cout << "NO\n";
		else {
			int num_piece = 1;
			while (w % 2 == 0) {
				num_piece *= 2;
				w /= 2;
			}
			while (h % 2 == 0) {
				num_piece *= 2;
				h /= 2;
			}
			if (num_piece >= n) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}