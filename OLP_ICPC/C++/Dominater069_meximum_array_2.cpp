#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
/*
#if !ONLINE_JUDGE && !EVAL
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
*/
	ll t;
	cin >> t;
	while (t--) {
		ll n, k, q;
		cin >> n >> k >> q;
		vector<ll> a(n + 1, 0), mn(n + 1, 0), mx(n + 1, 0);
		while (q--) {
			ll c, l, r;
			cin >> c >> l >> r;
			for (ll i = l; i <= r; ++i)
				if (c == 1) mn[i] = 1;
				else mx[i] = 1;
		}
		for (ll i = 1; i <= n; ++i)
			if (mn[i] == 1 && mx[i] == 1) a[i] = k + 1;
			else if (mx[i] == 1) a[i] = i % k;
			else a[i] = k;
		for (ll i = 1; i <= n; ++i) cout << a[i] << ' ';
		cout << nl;
	}
}