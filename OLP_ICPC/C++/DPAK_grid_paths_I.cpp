#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    if (s[0][0] == '*') dp[0][0] = 0; // hoac la return 0 luon 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if (i - 1 >= 0 && s[i][j] != '*') {
            (dp[i][j] += dp[i-1][j]) %= mod; 
           }  
        if (j - 1 >= 0 && s[i][j] != '*') {
            (dp[i][j] += dp[i][j - 1]) %= mod; 
           }  
        }
    }
    cout << dp[n - 1][n - 1];
}