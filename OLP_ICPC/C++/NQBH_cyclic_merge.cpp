#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll &x : a) cin >> x;
		if (n == 2) {
			cout << max(a[0], a[1]) << '\n';
			continue;
		}
		ll S = 0;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] >= a[i + 1]) S += a[i];
			else S += a[i + 1];
		S += max(a[0], a[n - 1]);
		S -= *max_element(a.begin(), a.end());
		cout << S << '\n';		
	}
}