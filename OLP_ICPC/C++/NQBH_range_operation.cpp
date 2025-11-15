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
		ll S = 0;
		cin >> n;
		vector<ll> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			S += a[i]; // S = ps[n]
		}
		ll min_sub = 0;
        ll cur = 0;
        for (int i = 1; i <= n; ++i) {
            ll bi = a[i] - (2LL * i); // only change a[i] if a[i] < 2i
            cur += bi;
            min_sub = min(min_sub, cur);
            if (cur > 0) cur = 0;
        }        
        ll best = S - min_sub;
        cout << max(S, best) << '\n';
	}
}