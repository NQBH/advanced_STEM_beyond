#include <iostream>
#include <vector>

int count_self_conjugate(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int k = 1; k <= n; k += 2) {
        for (int i = n; i >= k; --i) {
            dp[i] += dp[i - k];
        }
    }
    return dp[n];
}

int main() {
    int n = 7;
    std::cout << "Số phân hoạch tự liên hợp của " << n << " là: " << count_self_conjugate(n) << "\n";
    return 0;
}
