#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int map[6][6]; // adjacency matrix

void makemap() { // generating adjacency matrix
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j)
			if (i != j) map[i][j] = 1;
	map[4][1] = map[1][4] = 0;
	map[4][2] = map[2][4] = 0;
}

void dfs(int x, int k, string s) { // DFS traversal
	s += char(x + '0'); // vertex x is pushed into sequence
	if (k == 8) { // drawing the house is finished
		cout << s << '\n';
		return;
	}
	for (int y = 1; y <= 5; ++y) // in increasing order visit edges
		if (map[x][y]) {
			map[x][y] = map[y][x] = 0;
			dfs(y, k + 1, s);
			map[x][y] = map[y][x] = 1;
		}
}

int main() {
	makemap(); // generating adjacency matrix
	dfs(1, 0, ""); // all possibilities are outputed by increasing order
}