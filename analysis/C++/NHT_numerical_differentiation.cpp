#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mod = 1e9 + 7;
int n;
ld x, h, res;
ld a[1000005];

/*ll Power(ll a, ll b){
    ll ans(1);
    for(; b; b >>= 1){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
    }
    return ans;
}*/

ld Qx(int x) {
    ld ans(0);
    for (int i = 0; i <= n; ++i)
        ans += (i * a[i] * pow(x, i));
    return ans;
}

ld forward(ld x, ld h) {
    ld ans(0), fx(0);
    for (int i = 0; i <= n; ++i)
        ans += (a[i] * pow(x + h, i));
    for (int i = 0; i <= n; ++i)
        fx += (a[i] * pow(x, i));
    ans -= fx;
    return ans / h;
}

ld backward(ld x, ld h) {
    ld ans(0), fx(0);
    for (int i = 0; i <= n; ++i)
        ans += (a[i] * pow(x - h, i));
    for (int i = 0; i <= n; ++i)
        fx += (a[i] * pow(x, i));
    ans = fx - ans;
    return ans / h;
}

ld stirling(ld x, ld h) {
    ld ans1(0), ans2(0);
    for (int i = 0; i <= n; ++i)
        ans1 += (a[i] * pow(x + h, i));

    for (int i = 0; i <= n; ++i)
        ans2 += (a[i] * pow(x - h, i));

    ld ans = ans1 - ans2;
    return ans / (2 * h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> h;
    for (int i = n; i >= 0; i--) cin >> a[i];

    res = Qx(x);
    //cout << "P'(xo) = " << res << endl;
    ld FORWARD = forward(x, h), BACKWARD = backward(x, h), STIRLING = stirling(x, h);
    cout << "Forward: " << FORWARD << endl;
    cout << "Backward: " << BACKWARD << endl;
    cout << "Stirling: " << STIRLING << endl;

    return 0;
}