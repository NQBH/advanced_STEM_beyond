#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<ll> a;
        for (ll i = 0; i<n;++i){
            int k; cin >> k;
            a.insert(k);
        }
        cout << a.size()*2 - 1 << "\n";

    }
}
