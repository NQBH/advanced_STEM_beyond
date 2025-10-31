#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
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
		int num_black_pos = 0;
		vector<int> black_x, black_y; // store row & column indices of black cells
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (grid[i][j] == '#') {
					++num_black_pos;
					black_x.push_back(i);
					black_y.push_back(j);
				}
		if (!num_black_pos) { // just color 1 white -> black
			cout << "YES\n";
			continue;
		}
		if (num_black_pos == 4 && black_x[3] - black_x[0] <= 1 && black_y[3] - black_y[0] <= 1) { // square 2x2
			cout << "YES\n";
			continue;
		}
		
		for (int i = 0; i < num_black_pos; ++i) cout << black_x[i] << ' ';
		cout << '\n';
		for (int i = 0; i < num_black_pos; ++i) cout << black_y[i] << ' ';
		cout << '\n';
		
		int diff0 = black_y[0] - black_x[0];
		bool type1 = true, type2 = true, type3 = true, type4 = true;
		if (black_y[0] < black_y[num_black_pos - 1]) { // zigzag top-left -> bot-right
			type3 = false, type4 = false;
			for (int i = 1; i < num_black_pos; ++i ) {
				int diff = black_y[i] - black_x[i] - diff0;
				if (diff != 0 && diff != 1) type1 = false;
				if (diff != 0 && diff != -1) type2 = false;
			}
		} else { // zigzag top-right -> bot-left
			type1 = false, type2 = false;
			for (int i = 1; i < num_black_pos; ++i ) {
				int diff = black_y[i] - black_x[i] - diff0;
				if (diff != 0 && diff != 1) type4 = false;
				if (diff != 0 && diff != -1) type3 = false;
			}
		}
		if (type1 || type2 || type3 || type4) cout << "YES\n";
		else cout << "NO\n";
	}
}