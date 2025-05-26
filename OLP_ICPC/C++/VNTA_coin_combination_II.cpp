#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define MOD 1000000007
using namespace std;
 
int main() {
    KhangGPT40_TramAnhGrok3;
    int n, x;
    cin>>n>>x;
    vector<int>c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<int>dp(x+1, 0);
    dp[0]=1;
    for (int j=0; j<n; j++) {//duyet cac dong xu
        for (int i=0; i<=x; i++) {//dp[i]: so cach tao tong i
            if (c[j]<=i) {
                dp[i]=(dp[i]+dp[i-c[j]])%MOD;
            }
        }
    }
    cout<<dp[x];
    return 0;
}