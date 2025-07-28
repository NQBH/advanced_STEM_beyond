#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Hàm tính số phân hoạch p_max(n, k)
 * Đếm số cách phân hoạch n có phần tử lớn nhất là k
 */
int count_p_max(int n, int k) {
    if (n < k || k <= 0) {
        return 0; // Không thể có phân hoạch
    }
    if (n == k) {
        return 1; // Chỉ có một phân hoạch là {k}
    }

    int target = n - k; // phân hoạch số `target` với các phần tử <= k

    // Bảng quy hoạch động: dp[i][j] là số cách phân hoạch số i với các phần tử <= j
    vector<vector<int>> dp(target + 1, vector<int>(k + 1, 0));

    // Trường hợp cơ sở: có 1 cách để phân hoạch số 0 (là phân hoạch rỗng)
    for (int j = 0; j <= k; ++j) {
        dp[0][j] = 1;
    }

    // Điền bảng quy hoạch động
    for (int i = 1; i <= target; ++i) {
        for (int j = 1; j <= k; ++j) {
            // Cách 1: Không dùng phần tử j. Số cách bằng phân hoạch i với các phần tử <= j-1
            dp[i][j] = dp[i][j - 1];
            
            // Cách 2: Dùng ít nhất một phần tử j
            if (i >= j) {
                dp[i][j] += dp[i - j][j];
            }
        }
    }

    return dp[target][k];
}

int main() {
    int n, k;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Nhap phan tu lon nhat k: ";
    cin >> k;

    cout << "So phan hoach cua " << n << " co phan tu lon nhat la " << k << " la: "
         << count_p_max(n, k) << endl;

    return 0;
}