// b) số s hoán vị của A chứa mỗi phần tử ít nhất 1 lần
#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

long long stirling2(int s, int t) {
    vector<vector<long long>> dp(s + 1, vector<long long>(t + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= t; ++j) {
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    return dp[s][t];
}

int main() {
    int s, t;
    cout << "Nhap do dai xau s: ";
    cin >> s;
    cout << "Nhap so loai ky tu t: ";
    cin >> t;

    if (t > s || t <= 0) {
        cout << "Khong co hoan vi nao thoa man (t > s hoac t <= 0)." << endl;
    } else {
        long long result = factorial(t) * stirling2(s, t);
        cout << "So hoan vi do dai " << s << " chua moi ky tu it nhat 1 lan la: " << result << endl;
    }

    return 0;
}
