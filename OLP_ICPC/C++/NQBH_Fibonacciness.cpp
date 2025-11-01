#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = a + b, ans1 = 1, ans2 = 1;
		if (b + x == c) ++ans1;
		if (x + c == d) ++ans1;
		x = d - c;
		if (b + x == c) ++ans2;
		if (a + b == x) ++ans2;
		cout << max(ans1, ans2) << '\n';
	}
}