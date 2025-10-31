#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<ll> a(n), ans;
		for (ll &x : a) cin >> x;
		sort(a.begin(), a.end());
		ll S = 0, bonus = 0;
		int l = 0, r = n - 1;
		while (l <= r) {
			if (a[l] >= x - (S % x)) { // a[i] give bonus
				S += a[r];
				ans.push_back(a[r]);
				bonus += a[r];
				--r;
			} else {
				S += a[l];
				ans.push_back(a[l]);
				++l;
			}
		}
		cout << bonus << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';		
	}
}