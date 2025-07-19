#include <bits/stdc++.h>
using namespace std;

int main() {
    int test = 0;
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        int n = s.size();
        int m = t.size();
        s = " " + s + " ";
        t = " " + t + " ";
        for (int i = 1; i <= n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] == ' ') continue;
            s[i] = ' ';
        }
        for (int i = 1; i <= m; ++i) {
            if (t[i] >= 'A' && t[i] <= 'Z' || t[i] >= 'a' && t[i] <= 'z' || t[i] == ' ') continue;
            t[i] = ' ';
        }
        vector<string> a(1), b(1);
        string temp;
        for (int i = 1; i <= n + 1; ++i)
            if (s[i] == ' ') {
                if (temp.empty() == false) {
                    a.push_back(temp);
                    temp.clear();
                }
            }
            else temp += s[i];
        temp.clear();
        for (int i = 1; i <= m + 1; ++i)
            if (t[i] == ' ') {
                if (temp.empty() == false) {
                    b.push_back(temp);
                    temp.clear();
                }
            }
            else temp += t[i];
        n = a.size() - 1;
        m = b.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (dp[n][m] == 0) cout << setw(2) << ++test << ". Blank!";
        else cout << setw(2) << ++test << ". Length of longest match: " << dp[n][m];
        cout << '\n';
    }
}