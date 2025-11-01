#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y, a;
		cin >> x >> y >> a;
		int rem = (a + 1) % (x + y);
		if (0 < rem && rem <= x) cout << "NO\n";
		else cout << "YES\n";
	}
}