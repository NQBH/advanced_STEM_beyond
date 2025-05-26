#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define MOD 1000000007
using namespace std;
 
int main() {
    KhangGPT40_TramAnhGrok3;
    int n, x;
    cin>>n>>x;
    vector<int>c(n);
    for(int i=0; i<n; i++) cin>>c[i]; //{1,5,7}
    vector<int>dp(x+1, INT_MAX);
    dp[0]=0;
    for (int i=1; i<=x; i++) { //dp[i]: so dong xu min co tong i
        for (int j=0; j<n; j++) { //duyet cac dong xu
            if (c[j]<=i && dp[i-c[j]]!=INT_MAX) {
                dp[i]=min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    if (dp[x]==INT_MAX) cout<<-1;
    else cout<<dp[x];
    return 0;
}