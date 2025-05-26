#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=1;i<=n;++i) dp[i] = 1e9;
    dp[0] = 0;
    for(int i=1;i<=n;++i){
        ll tmp = i;
        while(tmp){
            ll digit = tmp % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            tmp /= 10;
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}