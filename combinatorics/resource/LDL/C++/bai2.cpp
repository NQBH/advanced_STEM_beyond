#include <bits/stdc++.h>
using namespace std;

// Ham dem so phan hoach cua n thanh dung k phan tu
int count_partitions_exact_parts(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1; // co 1 cach phan hoach 0 thanh 0 phan tu

    for (int i = 1; i <= n; i++) {       // tong can dat
        for (int j = 1; j <= k; j++) {   // so phan tu
            if (i >= j)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[n][k];
}

// Ham phu dem so phan hoach cua n voi phan tu lon nhat khong vuot qua k
int count_p_le_k(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int j = 0; j <= k; j++)
        dp[0][j] = 1; // 1 cach phan hoach 0

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j)
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][k];
}

// Ham dem so phan hoach cua n sao cho phan tu lon nhat la k
int count_partitions_max(int n, int k) {
    if (k > n) return 0;
    return count_p_le_k(n, k) - count_p_le_k(n, k - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;

    int p_k = count_partitions_exact_parts(n, k);
    int p_max = count_partitions_max(n, k);

    cout << "\np_k(" << n << ") = " << p_k << "\n";
    cout << "p_max(" << n << "," << k << ") = " << p_max << "\n";

    return 0;
}