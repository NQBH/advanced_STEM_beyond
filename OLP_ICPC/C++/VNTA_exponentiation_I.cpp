#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7;
 
long long ppow(long long a, long long b, int mod) {
    if (a==0&&b==0) return 1;
    long long res=1;
    a%=mod;
    while (b>0) {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    long long a,b;
    while(n--) {
        cin>>a>>b;
        cout<<ppow(a,b,MOD)<<'\n';
    }
}