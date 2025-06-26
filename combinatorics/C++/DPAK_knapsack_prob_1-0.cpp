#include <bits/stdc++.h>

using namespace std;

/*
(a) :

vì w_i = 1, \forall{i} \in [n], và {v_i} là dãy tăng ngặt
--> Balo dung lượng W, ta chỉ cần lấy các item từ n - W  + 1 --> n

*/

// dp[i][j] : Tổng v lớn nhất khi xét i món dầu, dung lượng hiện tại là j

struct ii {
    int w;
    double v;
};

void c() {
    int n, w;
    cin >> n >> w;

    vector<ii> item(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> item[i].w >> item[i].v;
    }
    vector<vector<double>> dp(n + 1, vector<double>(w + 1, 0.0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - item[i].w >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - item[i].w] + item[i].v);
            }
        }
    }
    cout << dp[n][w];
}

void d() {
    int n, w;
    cin >> n >> w;

    vector<ii> item(n + 1);
    for (int i = 1; i <= n; i++) {
        //cin >> item[i].w; item[i].v = i;
        item[i].w = i;
    }

    // f[i][j] : số cách chọn khi xét item[1..j], tổng trọng lượng balo = j
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - item[i].w >= 0) {
                dp[i][j] += dp[i - 1][j - item[i].w];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++) {
        ans += dp[n][i];
    }
    cout << ans;
}

/*
n = 5, W = 10

3 2 5 7 4

[3], [2], [5], [7], [4],
[3, 2], [3, 5], [3, 7], [3, 4],
[2, 5], [2, 7], [2, 4]
[5, 4]

*/
int main() {

    d();
}