#include <iostream>
#include <vector>
using namespace std;

// Ham dem so phan hoach cua n voi so lon nhat la k
int countPartitionsMax(int n, int k) {
    // Tao bang 2 chieu dp[n+1][k+1], khoi tao toan bo = 0
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Co 1 cach de phan hoach 0 voi moi k
    for (int j = 0; j <= k; ++j)
        dp[0][j] = 1;

    // Duyet cac gia tri tu 1 den n va 1 den k
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0)
                // Chon j: cong don khong chon j + chon j
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                // Khong the chon j vi lon hon i
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;

    // In ket qua
    cout << "So phan hoach cua " << n << " voi so lon nhat la " << k
         << " la: " << countPartitionsMax(n, k) << endl;

    return 0;
}