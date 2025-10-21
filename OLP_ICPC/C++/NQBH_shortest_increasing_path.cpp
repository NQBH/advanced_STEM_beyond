#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x < y) cout << 2 << '\n';
		else if (x - y >= 2 && y > 1) cout << 3 << '\n';
		else cout << -1 << '\n';
	}
}