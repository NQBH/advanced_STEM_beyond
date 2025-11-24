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

#if !ONLINE_JUDGE && !EVAL
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	ll t;
	cin >> t;
	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> a(n + 1, 0), sgn(n + 1, 0);
		for (ll i = 1; i <= n; ++i) cin >> a[i];
		sort(a.begin() + 1, a.end());
		ll balance = 0;
		for (ll i = 1; i <= n; ++i)
			if (a[i] < l) sgn[i] = 1, ++balance;
			else if (a[i] > r) sgn[i] = -1, --balance;
		for (ll i = 1, j = n; i <= n && j >= 1; ++i, --j) {
			if (sgn[i] == 0 && balance < 0) sgn[i] = 1, ++balance;
			if (sgn[j] == 0 && balance > 0) sgn[j] = -1, --balance;
		}
		ll rem = 0;
		for (ll i = 1; i <= n; ++i) rem += (sgn[i] == 0);
		for (ll i = 1, j = 1; i <= n && j <= rem / 2; ++i)
			if (sgn[i] == 0) sgn[i] = 1, ++j;
		for (ll i = n, j = 1; i >= 1 && j <= rem / 2; --i)
			if (sgn[i] == 0) sgn[i] = -1, ++j;
		ll score_l = 0, score_r = 0;
		for (ll i = 1; i <= n; ++i)
			if (sgn[i] == 1) score_l += l - a[i], score_r += r - a[i];
			else if (sgn[i] == -1) score_l += a[i] - l, score_r += a[i] - r;
		ll ans = min(score_l, score_r);
		cout << ans << nl;
	}
}