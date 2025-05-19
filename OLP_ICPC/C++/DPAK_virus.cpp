#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

const int mod = 1e9 + 7;
void fib(long n, long k) {
    vector<int>dp(k + 2, 0);
    // dp[i] la so luong ca the o ngay i
    dp[0] = n; // n = 5 , k = 3
    for (int j = 1; j <= k; j++) {
    vector<int> temp(k + 2, 0);
        for (int i = k; i >= 1; i--){
            temp[i] = dp[i - 1] % mod;
        }
        int cur = 0;
        for (int i = 0; i <= k; i++) {
            cur+= dp[i] * (i + 1) ;
            cur %= mod;
        }
        dp = temp;
        dp[0] = cur;
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
        res += dp[i] % mod;
    }
    cout << "AK: " << res << endl;
}

int main(){
    KhangGPT40_TramAnhGrok3;
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        fib(n,k);
    }

    return 0;
}
