#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while(t--){
        ll n,k; cin>>n>>k;
        string s;
        cin>>s;
        ll ans = 0,dem = 0;
        for (ll i = 0;i<n;++i){
            if(i-k >= 0){
                dem-=(s[i-k]=='1'? 1 : 0);
            }
            if (s[i]=='1'){
                if (dem == 0) {
                    ans++;
                }
                dem+=(s[i]=='1'? 1 : 0);
            }
        }
        cout << ans << "\n";
    }
}
