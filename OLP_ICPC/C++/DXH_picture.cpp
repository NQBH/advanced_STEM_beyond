#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countWays(int n, int k) {
        if (n < 0 || k <= 0 || k > n || n > 50) return 0;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int t, n, k;
    cin >> t; // nhập t (test case)
    
    Solution sol;
    while (t--) {
        cin >> n >> k; // Nhập n và k từ bàn phím
        cout << sol.countWays(n, k) << endl; // Xuất kết quả ra màn hình
    }
    
    return 0;
}