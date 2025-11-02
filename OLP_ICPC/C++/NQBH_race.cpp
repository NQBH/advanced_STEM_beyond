#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, x, y;
		cin >> a >> x >> y;
		int b = (x + y) / 2;
		if ((abs(b - x) < abs(a - x) && abs(b - y) < abs(a - y)) || abs(x - y) < abs(a - y) || abs(y - x) < abs(a - x)) cout << "YES\n";
		else cout << "NO\n";
	}
}