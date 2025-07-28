#include <iostream>
#include <vector>
using namespace std;

int p_self_dp(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int ki = 1; ki <= k; ++ki) {
        for (int ni = 0; ni <= n; ++ni) {
            if (ni >= 2 * ki - 1)
                dp[ni][ki] = dp[ni - (2 * ki - 1)][ki - 1];
        }
    }

    return dp[n][k];
}

int main() {
    int n = 13, k = 3;
    cout << "DP: p_" << k << "^{selfcjg}(" << n << ") = "
         << p_self_dp(n, k) << endl;
    return 0;
}