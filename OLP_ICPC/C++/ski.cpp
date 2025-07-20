#include <cstdio>
using namespace std;

int n, m, s1[5], s2[5], ans; // size of ski area is n * m; ans: length of longest viable skidway
int a[105][105], c[105][105]; // adjacency matrix for ski area a[][], state transition equation c[][]
bool f[105][105]; // visited mark

void work(int x, int y) { // recursively calculate length of longest viable skidway c[x][y] starting from (x, y)
	int xx, yy;
	f[x][y] = true; // set visited mark for (x, y)
	c[x][y] = 1; // initialization
	for (int i = 1; i <= 4; ++i) { // 4 adjacent points
		xx = x + s1[i]; yy = y + s2[i]; // (xx, yy): adjacent point in direction i
		if (a[xx][yy] < a[x][y] && xx > 0 && xx <= n && yy > 0 && yy <= m) { // (xx, yy) is in the area, can be skied down from (x, y), isn't visited
			if (!f[xx][yy]) work(xx, yy);
			c[x][y] = c[x][y] > (c[xx][yy] + 1) ? c[x][y] : (c[xx][yy] + 1);
		}
	}
}

int main() {
	s1[1] = -1; s2[1] = 0; s1[2] = 1; s2[2] = 0;
	s1[3] = 0; s2[3] = -1; s1[4] = 0; s2[4] = 1;
	scanf("%d%d", &n, &m); // number of rows & columns
	for (int i = 1; i <= n; ++i) // heights of points
		for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
	ans = 0; // initialization
	for (int i = 1; i <= n; ++i) // heights of points
		for (int j = 1; j <= m; ++j)
			if (!f[i][j]) {
				work(i, j);
				ans = ans > c[i][j] ? ans : c[i][j];
			}
	printf("%d\n", ans); // output result
}