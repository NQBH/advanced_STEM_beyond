#include <iostream>
using namespace std;

int main() {
	int a1, b1, c1, d1, a2, b2, c2, d2;
	cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
	int l = min(a1, a2), r = max(c1, c2), b = min(b1, b2), t = max(d1, d2);
	int ans = max(r - l, t - b);
	cout << ans * ans << '\n';
}