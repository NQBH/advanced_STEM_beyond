#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int dp[5005][5005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str1 >> str2;
    for(int i=0; i <= str1.size(); i++)
        for(int j=0; j <= str2.size(); j++)
            dp[i][j] = INT_MAX;

    dp[0][0] = 0;
    for(int i=0; i <= str1.size(); i++)
        for(int j=0; j <= str2.size(); j++){
            if(i != 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); // Xoá ký tự thứ (i − 1) của chuỗi ban đầu.
            if(j != 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); // Thêm ký tự thứ (j − 1) của chuỗi đích vào chuỗi ban đầu.
            // Biến ký tự thứ (i − 1) của chuỗi ban đầu
            // thành ký tự thứ (j − 1) của chuỗi đích
            // (giữ nguyên nếu trùng, thay thế nếu khác).
            if(i != 0 && j != 0){
                int cost = dp[i-1][j-1] + (str1[i-1] != str2[j-1]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    cout << dp[str1.size()][str2.size()] << '\n';

    return 0;
}

/*
 dp[i][j] là số bước ít nhất để
 biến i ký tự đầu tiên của chuỗi ban đầu
 thành j ký tự đầu tiên của chuỗi kết quả.
*/