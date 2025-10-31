#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	using ll = long long;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto &i : a) cin >> i;
		for (ll x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}) {
			int ok = 0;
			for (ll i : a) {
				if (i % x) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				cout << x << '\n';
				break;
			}
		}
	}
}