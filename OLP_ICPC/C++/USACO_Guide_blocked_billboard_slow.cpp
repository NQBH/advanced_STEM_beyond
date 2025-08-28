#include <iostream>
using namespace std;

const int MAX_POS = 2000;
bool visible[MAX_POS][MAX_POS];

int main() {
	for (int i = 0; i < 3; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// make all the coordinates positive
		x1 += MAX_POS / 2;
		y1 += MAX_POS / 2;
		x2 += MAX_POS / 2;
		y2 += MAX_POS / 2;
		for (int x = x1; x < x2; ++x) // mark billboard area as visible, truck as not visible
			for (int y = y1; y < y2; ++y) visible[x][y] = i < 2;
	}
	// count all visible billboard squares
	int ans = 0;
	for (int x = 0; x < MAX_POS; ++x)
		for (int y = 0; y < MAX_POS; ++y) ans += visible[x][y];
	cout << ans << '\n';
}