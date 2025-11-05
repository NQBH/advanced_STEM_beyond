#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a >= b) cout << a << '\n';
		else cout << max(2 * a - b, 0) << '\n';
	}
}