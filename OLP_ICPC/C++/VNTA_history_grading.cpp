#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lis(vector<int>&a) {
    int n = a.size(), res = 1;
    vector<int>dp(n, 1);
    //dp[i] = do dai LIS ket thuc tai a[i]
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int>c(n);
    vector<int>pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        pos[i + 1] = c[i] - 1;
    }
    string s;
    cin.ignore();
    while (getline(cin, s)) {
        if (s.empty()) break;

        istringstream iss(s);
        vector<int>r(n);
        for (int i = 0; i < n; ++i) iss >> r[i];
        vector<int> sr(n);
        for (int i = 0; i < n; ++i) {
            sr[r[i] - 1] = i + 1;
        }

        vector<int> m(n);
        for (int i = 0; i < n; ++i) {
            m[i] = pos[sr[i]];
        }
        cout << lis(m) << '\n';
    }
}