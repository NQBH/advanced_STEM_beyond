#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (m == 0) {
			if (n % 2 == 0) cout << "YES\n";
			else cout << "NO\n";
		} else { // no constraints: (x, y): even if x + y % 2 = 0, else odd, when n is even, number of odd cells = number of even cells = n^2 / 2, when n is odd, number of odd chells = (n^2 - 1) / 2, number of even cells = (n^2 + 1) / 2 = number of odd cells + 1
			int num_blocked_odd = 0, num_blocked_even = 0;
			vector<vector<int>> chessboard(n + 1, vector<int>(n + 1, 1));
			for (int i = 1; i <= m; ++i) {
				int x, y;
				cin >> x >> y;
				if (chessboard[x][y]) { // not blocked yet
					chessboard[x][y] = 0; // blocked;
					if ((x + y) & 1) ++num_blocked_odd;
					else ++num_blocked_even;
				}
			}
			if (n & 1) {
				if (num_blocked_even == num_blocked_odd + 1) cout << "YES\n";
				else cout << "NO\n";
			} else { // n even
				if (num_blocked_odd == num_blocked_even) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}