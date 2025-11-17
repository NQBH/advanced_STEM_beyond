#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--){
        ll a,b,c; cin >> a >> b >> c;
        cout << max({a,b,c}) + 1 << "\n";
    }
}
