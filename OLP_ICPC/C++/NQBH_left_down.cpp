#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		if (max(a, b) <= k) cout << "1\n";
		else if (a == b) cout << "1\n";
		else {
			ll g = gcd(a, b);
			a /= g;
			b /= g;
			if (max(a, b) <= k) cout << "1\n";
			else cout << "2\n";
		}	
	}
}