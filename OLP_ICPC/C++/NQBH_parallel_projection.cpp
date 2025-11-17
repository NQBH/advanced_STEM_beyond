#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int w, d, h, a, b, f, g;
		cin >> w >> d >> h >> a >> b >> f >> g;
		cout << min({abs(a - f) + b + h + g, abs(a - f) + d - b + h + d - g, a + h + f + abs(b - g), w - a + h + w - f + abs(b - g)}) << '\n';
	}
}