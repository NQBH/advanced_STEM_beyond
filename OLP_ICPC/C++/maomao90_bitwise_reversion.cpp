#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXL = 60;
int t;
ll x, y, z;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		ll a = 0, b = 0, c = 0;
		bool ans = true;
		for (int l = MAXL - 1; l >= 0; --l) {
			ll bit_x = x >> l & 1, bit_y = y >> l & 1, bit_z = z >> l & 1;
			bool found = false;
			for (ll bit_a : {0, 1}) {
				for (ll bit_b : {0, 1}) {
					for (ll bit_c : {0, 1}) {
						if ((bit_a & bit_b) == bit_x && (bit_b & bit_c) == bit_y && (bit_a & bit_c) == bit_z) {
							found = true;
							a |= bit_a << l;
							b |= bit_b << l;
							c |= bit_c << l;
							break;
						}
					}
					if (found) break;
				}
				if (found) break;
			}
			if (!found) {
				ans = false;
				break;
			}
		}
		if (!ans) cout << "NO\n";
		else {
			assert((a & b) == x);
			assert((b & c) == y);
			assert((a & c) == z);
            cout << "YES\n";
		}
	}
}