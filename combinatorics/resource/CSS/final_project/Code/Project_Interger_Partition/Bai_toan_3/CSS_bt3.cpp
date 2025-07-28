#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_self_conjugate(const vector<int>& partition) {
    int max_val = *max_element(partition.begin(), partition.end());
    vector<int> transpose;
    for (int i = 1; i <= max_val; i++) {
        int count = 0;
        for (int val : partition) if (val >= i) count++;
        transpose.push_back(count);
    }
    return partition == transpose;
}

void generate_self_conjugate(int n, int k, int max_val, vector<int>& current, vector<vector<int>>& results) {
    if (k == 0) {
        if (n == 0 && is_self_conjugate(current))
            results.push_back(current);
        return;
    }
    if (n < k) return;
    for (int i = 1; i <= min(n - k + 1, max_val); i++) {
        current.push_back(i);
        generate_self_conjugate(n - i, k - 1, i, current, results);
        current.pop_back();
    }
}

int count_self_conjugate_recursive(int n, int k) {
    if (k == 1) return n == 1 ? 1 : 0;
    if (n < k || k <= 0) return 0;
    int result = 0;
    for (int m = 1; m <= k / 2; m++)
        result += count_self_conjugate_recursive(n - k*k + (k - 2*m)*(k - 2*m), k - 2*m);
    return result;
}

int count_self_conjugate_dp(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int m = 1; m <= j / 2; m++)
                if (i - j*j + (j - 2*m)*(j - 2*m) >= 0)
                    dp[i][j] += dp[i - j*j + (j - 2*m)*(j - 2*m)][j - 2*m];
    return dp[n][k];
}

int count_odd_partitions(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - j][j] + (j > 1 ? dp[i - 1][j - 1] : 0);
    int sum = 0;
    for (int k = 1; k <= n; k += 2) sum += dp[n][k];
    return sum;
}

int main() {
    int n, k;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap k: "; cin >> k;
    vector<int> current;
    vector<vector<int>> results;
    generate_self_conjugate(n, k, n, current, results);
    cout << "p_" << k << "^" << "{selfcjg}(" << n << ") = " << results.size() << endl;
    cout << "Cac phan hoach tu lien hop:" << endl;
    for (const auto& p : results) {
        for (int val : p) cout << val << " ";
        cout << endl;
    }
    cout << "p_" << k << "^" << "{selfcjg}(" << n << ") (de quy) = " << count_self_conjugate_recursive(n, k) << endl;
    cout << "p_" << k << "^" << "{selfcjg}(" << n << ") (quy hoach dong) = " << count_self_conjugate_dp(n, k) << endl;
    int p_odd = count_odd_partitions(n);
    cout << "So phan hoach co le phan = " << p_odd << endl;
    cout << "So sanh: p_" << k << "^" << "{selfcjg}(" << n << ") <= so phan hoach co le phan is " << (results.size() <= p_odd) << endl;
    return 0;
}