#include <bits/stdc++.h>
using namespace std;
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)

struct item {
    long long w;
    double v;
};

double solve(int n, long long W, vector<item>& p) {
    vector<vector<double>> dp(n + 1, vector<double>(W + 1, 0.0));
    for (int i = 1; i <= n; ++i) {
        for (long long j = 0; j <= W; ++j) {
            if (p[i - 1].w > j) dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i - 1].w] + p[i - 1].v);
        }
    }
    return dp[n][W];
}

int main() {
    KhangGPT40_TramAnhGrok3;
    int n;
    long long W;
    cin >> n >> W;
    vector<item>p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].w >> p[i].v;
    cout << solve(n, W, p);
}