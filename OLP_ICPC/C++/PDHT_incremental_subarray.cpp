#include <bits/stdc++.h>
#define ll long long
#define for(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll n, m, ans; cin >> n >> m;
        vector<ll> a(m);
        for (i, m) cin >> a[i];
        bool hasDrop = false;
        for (i, m - 1) {
            if (a[i] >= a[i + 1]) {
                hasDrop = true;
                break;
            }
        }
        if (hasDrop) ans = 1;
        else ans = n - a[m - 1] + 1;
        cout << ans << "\n";
    }
}