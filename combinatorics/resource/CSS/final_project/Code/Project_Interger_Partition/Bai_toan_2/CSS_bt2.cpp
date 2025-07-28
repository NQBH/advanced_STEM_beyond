#include <iostream>
#include <vector>
using namespace std;

int count_partitions(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(i, k); j++)
            dp[i][j] = dp[i - j][j] + (j > 1 ? dp[i - 1][j - 1] : 0);
    return dp[n][k];
}

int count_max_partitions(int n, int k) {
    return n >= k ? count_partitions(n - k, k - 1) : 0;
}

int main() {
    int n, k;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap k: "; cin >> k;
    int pk_n = count_partitions(n, k);
    int pmax_n_k = count_max_partitions(n, k);
    cout << "p_" << k << "(" << n << ") = " << pk_n << endl;
    cout << "p_max(" << n << "," << k << ") = " << pmax_n_k << endl;
    cout << "So sanh: p_max(" << n << "," << k << ") <= p_" << k << "(" << n << ") is " << (pmax_n_k <= pk_n) << endl;
    return 0;
}