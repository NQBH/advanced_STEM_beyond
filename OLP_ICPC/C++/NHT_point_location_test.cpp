#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		ll area = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
		if (area > 0)
			cout << "LEFT\n";
		else if (area < 0)
			cout << "RIGHT\n";
		else
			cout << "TOUCH\n";
	}

	return 0;
}