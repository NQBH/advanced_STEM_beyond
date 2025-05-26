#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define MOD 1000000007
using namespace std;
 
int main() {
    KhangGPT40_TramAnhGrok3;
    int n;
    cin>>n;
    vector<long long> dp(n+1, 0);
    dp[0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=6 && j<= i; j++) {
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[n];
    return 0;
}