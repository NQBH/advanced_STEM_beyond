#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_SIDE = 1000;
int tree_pref[MAX_SIDE + 1][MAX_SIDE + 1], forest[MAX_SIDE + 1][MAX_SIDE + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	// read in the initial trees
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			char a;
			cin >> a;
			forest[i + 1][j + 1] += a == '*';
		}
	// build the prefix sum array
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] + tree_pref[i][j - 1] - tree_pref[i - 1][j - 1];
	for (int i = 0; i < q; ++i) {
		int from_row, to_row, from_col, to_col;
		cin >> from_row >> from_col >> to_row >> to_col;
		cout << tree_pref[to_row][to_col] - tree_pref[from_row - 1][to_col] - tree_pref[to_row][from_col - 1] + tree_pref[from_row - 1][from_col - 1] << '\n';
	}
}