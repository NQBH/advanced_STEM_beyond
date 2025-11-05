#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> a(n+2),b(n+2);
        for (ll i = 1; i<=n;++i){
            cin >> a[i];
        }
        b[0]=a[0]=0;
        a[n+1]=0;
        for (ll i =1;i<=n;++i){
            b[i] = max(b[i-1], a[i]);
        }
        ll ans=0;
        for (ll i =2;i<=n;i+=2){
            a[i] = b[i];
            if (a[i-1]>=a[i]){
                ans += a[i-1]-a[i]+1;
            }
            if (a[i+1]>=a[i]){
                ans += a[i+1]-a[i]+1;
                a[i+1] = a[i+1] - (a[i+1] - a[i]+1);
            }
        }
        cout << ans << "\n" ;
    }
}
