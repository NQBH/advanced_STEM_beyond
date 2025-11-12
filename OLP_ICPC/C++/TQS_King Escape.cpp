#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(7);
    for (ll i = 1; i <= 6; ++i)
    {
        cin >> a[i];
    }
    if ((a[4] < a[2] and a[2] < a[6]) or (a[4] > a[2] and a[2] > a[6]) or (a[3] > a[1] and a[1] > a[5]) or (a[3] < a[1] and a[1] < a[5])) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}
