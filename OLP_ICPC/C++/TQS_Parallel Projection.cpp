#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll w, d, h;
        cin >> w >> d >> h;
        ll a, b, f, g;
        cin >> a >> b >> f >> g;
        ll ans = h + abs(a - f) + min(b + g, 2 * d - b - g);
        ll ans1 = h + abs(b - g) + min(a + f, 2 * w - a - f);
        cout << min(ans, ans1) << "\n";
    }
}
