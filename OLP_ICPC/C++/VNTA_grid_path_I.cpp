#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define MOD 1000000007
using namespace std;
 
int main() {
    KhangGPT40_TramAnhGrok3;
    int n;
    cin>>n;
    vector<string> g(n);
    for(int i=0; i<n; i++) cin>>g[i];
    vector<vector<long long>>dp(n, vector<long long>(n,0)); //dp[i][j]: so cach di den moi o
    dp[0][0]= (g[0][0]=='.')?1:0;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (g[i][j]=='*') continue;
            if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD; //tu tren xuong
            if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD; //tu trai sang
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}