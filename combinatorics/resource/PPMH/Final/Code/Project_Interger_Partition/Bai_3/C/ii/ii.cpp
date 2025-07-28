#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSelfConjugateDP(int n, int k) {
    // dp[total][parts][max_val]
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, 0)));
    dp[0][0][n] = 1;

    for (int total = 0; total <= n; ++total) {
        for (int parts = 0; parts <= k; ++parts) {
            for (int max_val = 0; max_val <= n; ++max_val) {
                int val = dp[total][parts][max_val];
                if (val == 0) continue;
                for (int i = min(max_val, n - total); i >= 1; i -= 2) { 
                    if (total + i <= n && parts + 1 <= k) {
                        dp[total + i][parts + 1][i] += val;
                    }
                }
            }
        }
    }

    // Tổng tất cả cấu hình (n, k, *) > kết quả
    int result = 0;
    for (int i = 0; i <= n; ++i) {
        result += dp[n][k][i];
    }
    return result;
}

int main() {
    int n;
    int k;
    cout << "Nhập n: "; 
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    cout << "Quy hoạch động: " << countSelfConjugateDP(n, k) << endl;
    return 0;
}