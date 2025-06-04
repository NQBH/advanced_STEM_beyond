#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    vector<ll> b(k + 1);
    for (int m = 1; m < (1 << k); m++) {
        int numofd = 0;
        ll temp = n;
        for (int i = 0; i < k; i++) {
            if ((1 << i)&m) {
                numofd++;
                temp /= a[i];
            }
        }
        b[numofd] += temp;
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        if (i % 2 == 0) ans -= b[i];
        else ans += b[i];
    }
    cout << ans << endl;
    return 0;
}