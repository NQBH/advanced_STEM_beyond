#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (y - x == 1 || (x - y) % 9 == 8) cout << "YES\n";
		else cout << "NO\n";
	}
}