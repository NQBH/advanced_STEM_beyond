#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x1, y1, x2, y2;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		if ((x1 == 1 && y1 == 1) || (x1 == n && y1 == 1) || (x1 == 1 && y1 == m) || (x1 == n && y1 == m)
		 || (x2 == 1 && y2 == 1) || (x2 == n && y2 == 1) || (x2 == 1 && y2 == m) || (x2 == n && y2 == m)) cout << "2\n"; // 4 corners
		else if (x1 == 1 || x1 == n || x2 == 1 || x2 == n || y1 == 1 || y1 == m || y2 == 1 || y2 == m) cout << "3\n";
		else cout << "4\n";
	}
}