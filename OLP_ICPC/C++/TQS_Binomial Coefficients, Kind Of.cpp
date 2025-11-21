#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    vector<ll> ans(100005);
    ans[1] = 2;
    for (ll i = 2; i <= 100000; ++i) {
        ans[i] = (ans[i - 1] * 2) % 1000000007;
    }
    ll i = 0;
    while (n--) {
        cout << ans[b[i++]] << "\n";
    }
}
