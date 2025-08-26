#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
const int DIM = 8;

int main() {
	vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
	for (int r = 0; r < DIM; ++r) {
		string row;
		cin >> row;
		for (int c = 0; c < DIM; ++c) blocked[r][c] = row[c] == '*';
	}
	vector<int> queens(DIM);
	iota(queens.begin(), queens.end(), 0); // set the initial values to 0, 1,..., 7
	int valid_num = 0;
	do {
		bool works = true;
		for (int c = 0; c < DIM; ++c) // check if any cells have been blocked off by the input
			if (blocked[queens[c]][c]) {
				works = false;
				break;
			}
		// check the diagonals from the top-left to the bottom-right
		vector<bool> taken(DIM * 2 - 1);
		for (int c = 0; c < DIM; ++c) {
			if (taken[c + queens[c]]) { // check if the diagonal with sum has been taken
				works = false;
				break;
			}
			taken[c + queens[c]] = true;
		}
		// check the diagonals from the top-right to the bottom-left
		taken = vector<bool>(DIM * 2 - 1);
		for (int c = 0; c < DIM; ++c) {
			if (taken[queens[c] - c + DIM - 1]) { // queens[c] - c can be negative; the DIM - 1 offsets that
				works = false;
				break;
			}
			taken[queens[c] - c + DIM - 1] = true;
		}
		if (works) ++valid_num;
	} while (next_permutation(queens.begin(), queens.end()));
	cout << valid_num << '\n';
}