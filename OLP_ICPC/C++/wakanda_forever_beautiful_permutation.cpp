#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll query(int type, int l, int r) {
	ll x;
	cout << type << ' ' << l << ' ' << r << flush << '\n';
	cin >> x;
	return x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = query(2, 1, n);
		sum -= ((n * (n + 1)) / 2);
		ll diff = sum - 1;
		int l = 1, r = n;
		while (l < r) {
			int md = (l + r) / 2;
			ll val1 = query(1, 1, md);
			ll val2 = query(2, 1, md);
			if (val1 < val2) r = md;
			else l = md + 1;
		}
		cout << "!" << ' ' << l << ' ' << diff + l << flush << '\n';
	}
}