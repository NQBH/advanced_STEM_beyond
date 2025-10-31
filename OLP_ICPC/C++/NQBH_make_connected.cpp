#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, lim = 2e5 + 1;
		cin >> n;
		string s;
		vector<string> grid(n);
		for (int i = 0; i < n; ++i) cin >> grid[i];
		if (n == 1) {
			cout << "YES\n";
			continue;
		}
		bool block3 = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - 2; ++j)
				if (grid[i][j] == '#' && grid[i][j + 1] == '#' && grid[i][j + 2] == '#') block3 = true;
		if (!block3) {
			for (int j = 0; j < n; ++j)
				for (int i = 0; i < n - 2; ++i)
					if (grid[i][j] == '#' && grid[i + 1][j] == '#' && grid[i + 2][j] == '#') block3 = true;
		}
		if (block3) { // fail initially
			cout << "NO\n";
			continue;
		}
		// store positions of black cells
		int max_x = -lim, max_y = -lim, min_x = lim, min_y = lim, max_sum = -lim, min_sum = lim, max_diff = -lim, min_diff = lim; 
		int num_black_pos = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (grid[i][j] == '#') {
					++num_black_pos;
					max_x = max(max_x, i);
					min_x = min(min_x, i);
					max_y = max(max_y, j);
					min_y = min(min_y, j);
					max_sum = max(max_sum, i + j);
					min_sum = min(min_sum, i + j);
					max_diff = max(max_diff, i - j);
					min_diff = min(min_diff, i - j);
				}
		if (!num_black_pos) { // just color 1 white -> black
			cout << "YES\n";
			continue;
		}
		if (max_sum - min_sum <= 1 || max_diff - min_diff <= 1 || (max_x - min_x <= 1 && max_y - min_y <= 1)) cout << "YES\n";
		else cout << "NO\n";
	}
}