#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        ll k; cin >> k;
        a[i] = k;
    }
    for (ll i = 1; i <= n; ++i) {
        bool vis[n + 1] = {false};
        ll k = i;
        while (!vis[k]) {
            vis[k] = true;
            k = a[k];
        }
        cout << k << " ";
    }
}
