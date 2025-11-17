#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y, k;
		cin >> x >> y >> k;
		if (k <= min(x, y)) cout << "0 0 " << k << " 0\n0 0 0 " << k << '\n';
		else {
			int m = min(x, y);
			cout << "0 0 " << m << ' ' << m << "\n0 " << m << ' ' << m << " 0\n";
		}		
	}
}