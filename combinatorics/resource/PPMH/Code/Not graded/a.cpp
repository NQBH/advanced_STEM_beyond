// a) số cách đặt s bóng phân biệt và t hộp khác rỗng không phân biệt

#include <iostream>
#include <vector>
using namespace std;

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
    cout << "Nhap so bong phan biet (s): ";
    cin >> s;
    cout << "Nhap so hop khong phan biet khac rong (t): ";
    cin >> t;

    if (t > s || t <= 0) {
        cout << "Khong co cach nao (so hop > so bong hoac t <= 0)" << endl;
    } else {
        cout << "So cach dat " << s << " bong vao " << t << " hop khac rong (khong phan biet): ";
        cout << stirling2(s, t) << endl;
    }

    return 0;
}
