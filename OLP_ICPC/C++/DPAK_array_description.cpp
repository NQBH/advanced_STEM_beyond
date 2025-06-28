#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int>a(n + 1);
    for (int i =1 ; i <=n ;i++) {
        cin >> a[i];
    }

    // dp[i][j] : số array thỏa mãn khi xét đến a[1..i], giá trị hiện tại của a[i] là j
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));

    /*
    Nếu a[1] == 0 tức là a[1] hiện tại có thể mang giá trị từ 1 -> m, hay dp[1][j \in [1..m]] = 1 
    Nếu a[1] != 0 tức là a[1] đã có giá trị xác định --> dp[1][a[1]] = 1

    Từ i = 2, ta có 2 trường hợp như trên:
     - Nếu a[i] == 0, thì các giá trị có thể tăng để a[1..i] thỏa mãn sẽ là: 
            dp[i - 1][j + 1], dp[i - 1][j - 1], dp[i - 1][j], với j = 1 -> m
     - Ngược lại, các giá trị để a[1..i] thỏa mãn sẽ là:
            dp[i - 1][a[i] - 1] (tồn tại nếu a[i] > 1), dp[i - 1][a[i]], dp[i - 1][a[i] + 1] (tồn tại nếu a[i] < m)
    
    ====> Kết quả: sum(dp[n][j]), j = 1 -> m (hoặc có thể xét riêng a[n] != 0 thì ans = sum({dp[i - 1][a[n] - 1], dp[i - 1][a[i]], dp[i - 1][a[i] + 1]})
    */
    
    if (a[1] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[1][j] = 1;
        }
    }
    else {
        dp[1][a[1]] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0) {
                (dp[i][j] += dp[i-1][j-1] + dp[i-1][j + 1] + dp[i - 1][j]) %= mod;
                (dp[i][j] += mod) %= mod;
            }
            else {
                int v = a[i];
                dp[i][v] = dp[i-1][v];
                if (v > 1) (dp[i][v] += dp[i-1][v-1]) %= mod;
                if (v < m) (dp[i][v] += dp[i-1][v+1]) %= mod;
                (dp[i][v] += mod) %= mod;
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n][j] + mod;
        ans %= mod;
    }
    cout << ans;
    
    return 0;
}
