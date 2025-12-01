#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll kadane(const vector<ll>& a) {
    ll best = LLONG_MIN, cur = 0;
    for (ll x : a) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for (ll &x : a) cin >> x;
		for (ll &x : b) cin >> x;
		ll ans = kadane(a);
		if (!(k & 1)) cout << ans << '\n';
		else {
			for (int i = 0; i < n; ++i)
				if (a[i] + b[i] >= 0) {
					a[i] += b[i];
					ans = max(ans, kadane(a));
					a[i] -= b[i];
				}
			cout << ans << '\n';
		}
	}
}
// TLE test 7 CF