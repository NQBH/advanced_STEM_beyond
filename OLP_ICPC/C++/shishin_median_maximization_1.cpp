#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		ll L = 0, R = s + 1;
		while (R - L > 1) {
			ll M = (L + R) / 2;
			ll m = n / 2 + 1;
			if (m * M <= s) L = M;
			else R = M;
		}
		cout << L << '\n';
	}
}