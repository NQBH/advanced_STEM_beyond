#include <bits/stdc++.h>
#define ll long long
using namespace std;

double d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> d) {
		if (d == 0.00)
			break;
		int p = 2;
		while (d > 0) {
			d -= 1.0 / p;
			p++;
		}
		cout << p - 2 << " card(s)\n";
	}

	return 0;
}