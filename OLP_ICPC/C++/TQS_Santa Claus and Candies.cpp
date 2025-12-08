#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n; cin >> n;
    vector<ll> a;
    ll i = 1;
    while (i <= n) {
        a.push_back(i);
        n -= i;
        i++;
    }
    a[a.size() - 1] += n;
    cout << a.size() << "\n";

    for (ll i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
}
