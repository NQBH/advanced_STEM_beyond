#include <iostream>
#include <vector>
using namespace std;

// Tính p_k(n): phân hoạch n thành đúng k phần tử
int p_k(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;
    for (int num = 1; num <= n; ++num) {
        for (int i = n; i >= num; --i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] += dp[i - num][j - 1];
            }
        }
    }
    return dp[n][k];
}

// Tính p_max(n, k): phân hoạch n có phần tử lớn nhất bằng đúng k
int p_max(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int j = 0; j <= k; ++j) dp[0][j] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i >= j)
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][k] - (k > 0 ? dp[n][k - 1] : 0);
}

int main() {
    int n;
    int k;
    cout << "Nhập n: ";
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    cout << "p_" << k << "(" << n << ") = " << p_k(n, k) << endl;
    cout << "p_max(" << n << ", " << k << ") = " << p_max(n, k) << endl;
    return 0;
}
