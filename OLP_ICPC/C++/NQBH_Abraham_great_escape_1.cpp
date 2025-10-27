#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k == n * n - 1) cout << "NO\n";
		else if (k == n * n) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) cout << 'D';
				cout << '\n';
			}
		} else {
			cout << "YES\n";
			vector<vector<char>> s(n, vector<char>(n, 'D'));
			int num_unescape_cell = n * n - k;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (!num_unescape_cell) break;
					if (num_unescape_cell == 1 && j == 0) {
						s[i][j] = 'U';
						--num_unescape_cell;
						break;
					}
					if (j == 0) s[i][j] = 'R';
					else s[i][j] = 'L';
					--num_unescape_cell;
				}
				if (!num_unescape_cell) break;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) cout << s[i][j];
				cout << '\n';
			}
		}
	}
}