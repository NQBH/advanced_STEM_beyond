#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a;
ll n;

signed main() {
    cin >> n;
    a.resize(n);
    for (ll i = 1; i <= n; ++i) cin >> a[i - 1];
    ll mask = 1 << n;
    vector<ll> groupA, groupB;
    ll minWeight = INT_MAX;
    ll gA = 0, gB = 0;
    for (ll i = 0; i < mask; ++i) {
        ll sumA = 0, sumB = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) sumA += a[j];
            else sumB += a[j];
        }
        if (abs(sumA - sumB) < minWeight) {
            groupA.clear(); groupB.clear();
            for (ll j = 0; j < n; ++j)
                if (i & (1 << j)) groupA.push_back(a[j]);
                else groupB.push_back(a[j]);
            minWeight = abs(sumA - sumB);
            gA = sumA, gB = sumB;
        }
    }
    ll ans = abs(gA - gB);
    cout << ans << '\n';
    /*
    for (ll a : groupA) {
        cout << a << " ";
    }
    cout << '\n';
    for (ll b : groupB) {
        cout << b << " ";
    }
    */
}