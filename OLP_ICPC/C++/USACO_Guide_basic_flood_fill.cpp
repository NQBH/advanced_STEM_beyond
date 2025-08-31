#include <iostream>
using namespace std;

const int MAX_N = 1000;
int row_num, col_num, grid[MAX_N][MAX_N]; // the grid
int curr_size = 0; // reset to 0 each time we start a new component
bool visited[MAX_N][MAX_N]; // keep tarck of which nodes have been visited

void flood_fill(int r, int c, int color) {
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num) // if out of bounds
		|| grid[r][c] != color // wrong color
		|| visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
	++curr_size; // increment the size for each square we visit
	// recursively call flood fill for neighboring squares
	flood_fill(r, c + 1, color);
	flood_fill(r, c - 1, color);
	flood_fill(r - 1, c, color);
	flood_fill(r + 1, c, color);
}

int main() {
	/*
	 * input code and other problem-specific stuff here
	 */
	cin >> row_num >> col_num;
	for (int r = 0; r < row_num; ++r)
		for (int c = 0; c < col_num; ++c) cin >> grid[r][c];
	for (int i = 0; i < row_num; ++i)
		for (int j = 0; j < col_num; ++j) {
			if (!visited[i][j]) {
				curr_size = 0;
				/*
				 * start a flood fill if the square hasn't already been visited,
				 * & then store or otherwise use the component size for whatever it's needed for
				 */
				flood_fill(i, j, grid[i][j]);
			}
		}
}