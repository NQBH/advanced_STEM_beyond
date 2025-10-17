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

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(m + 1, 0);
        for (ll i = 1; i <= m; i++) cin >> a[i];

        ll ans = n - a[m] + 1;
        for (ll i = 2; i <= m; i++) {
            if (a[i] == 1) ans = 1;
        }

        cout << ans << nl;
    }

    return 0;
}