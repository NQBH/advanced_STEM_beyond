#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b) cout << 0 << '\n';
		else {
			if ((a - b) % (2 * c) == 0) cout << abs(a - b) / (2 * c) << '\n';
			else cout << abs(a - b) / (2 * c) + 1 << '\n';
		}
	}
}