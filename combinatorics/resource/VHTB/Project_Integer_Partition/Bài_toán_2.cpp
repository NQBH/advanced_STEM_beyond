#include <iostream>
#include <vector>

int count_partitions(int n, int k) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    for (int j = 0; j <= k; ++j)
        dp[0][j] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i >= j)
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[n][k];
}

int main() {
    int n = 5, k = 3;
    std::cout << "p(" << n << ", " << k << ") = " << count_partitions(n, k) << "\n";
    return 0;
}
