#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int xc, yc, k;
		cin >> xc >> yc >> k;
		if (k == 1) cout << xc << ' ' << yc << '\n';
		else {
			for (int i = 1; i <= k / 2; ++i)
				cout << xc - i << ' ' << yc << '\n' << xc + i << ' ' << yc << '\n';
			if (k & 1) cout << xc << ' ' << yc << '\n';
		}
	}
}