#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, ans1 = 0, ans2 = 0, ans3 = 0;
		cin >> a >> b >> c;
		if ((a & 1) == (b & 1)) ans3 = 1;
		if ((b & 1) == (c & 1)) ans1 = 1;
		if ((a & 1) == (c & 1)) ans2 = 1;
		cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	}
}