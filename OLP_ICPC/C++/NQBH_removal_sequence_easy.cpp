#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll x, y, k;
		cin >> x >> y >> k;
		if (y == 1) {
			cout << "-1\n";
			continue;
		}
		ll n = 1e12;
		for (int i = 0; i < x; ++i) n -= n / y;
		if (n < k) cout << "-1\n";
		else {
			for (int i = 0; i < x; ++i)
				
		}
		
	}
}
// unfinished