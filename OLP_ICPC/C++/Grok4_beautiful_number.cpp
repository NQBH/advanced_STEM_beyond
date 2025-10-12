#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count3(ll x) {
    if (x < 0) return 0;
    return x / 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    vector<ll> ex = {3, 9, 69, 999};
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll ans = count3(r) - count3(l - 1);
        for (ll e : ex) {
            if (l <= e && e <= r) ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}