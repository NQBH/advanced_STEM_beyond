#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 0;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0;
    ll kq = 1;
    ll zeros = 0;
    while (a[i] < 0 and i < n)
    {
        ans += (-a[i]) - 1;
        kq *= -1;
        i++;
    }
    int j = n - 1;
    while (a[j] > 0 and j >= 0)
    {
        ans += a[j] - 1;
        j--;
    }
    if (a[i] == 0) {
        zeros = j - i + 1;
    }
    ans += zeros;
    if (kq == -1)
    {
        if (zeros != 0) cout << ans << "\n";
        else cout << ans + 2 << "\n";
    }
    else cout << ans << "\n";
}
