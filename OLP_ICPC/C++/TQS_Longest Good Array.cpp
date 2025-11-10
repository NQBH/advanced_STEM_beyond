#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 1 << "\n";
            continue;
        }
        ll cnt = 1, k = 1;
        for (ll i = 2; i <= b - a + 1; i += k) {
            cnt++;
            k++;
        }
        cout << cnt << "\n";
    }
}
