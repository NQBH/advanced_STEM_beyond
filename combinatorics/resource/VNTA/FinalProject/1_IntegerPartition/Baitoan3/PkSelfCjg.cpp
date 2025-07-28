#include <bits/stdc++.h>
using namespace std;

bool isSelfConjugate(const vector<int>& parts) {
    int m = (int)parts.size();
    vector<int> conjugate;
    int maxPart = 0;
    for (int x : parts) maxPart = max(maxPart, x);

    for (int i = 1; i <= maxPart; i++) {
        int cnt = 0;
        for (int val : parts) {
            if (val >= i) cnt++;
            else break;
        }
        conjugate.push_back(cnt);
    }

    if (conjugate.size() != parts.size()) return false;
    for (int i = 0; i < (int)parts.size(); i++) {
        if (parts[i] != conjugate[i]) return false;
    }
    return true;
}

// (i) đệ quy
map<pair<int,int>, int> memo_recursive;

int p_selfcjg_recursive(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (n < 0 || k <= 0) return 0;
    if (k > n) return 0;

    pair<int,int> key = {n, k};
    if (memo_recursive.count(key)) return memo_recursive[key];

    int count = 0;
    vector<int> current;
    // Sinh phân hoạch có k phần tổng n theo maxVal
    function<void(int,int,int)> generate = [&](int remain, int parts, int maxVal) {
        if (parts == 0 && remain == 0) {
            vector<int> temp = current;
            sort(temp.rbegin(), temp.rend());
            if ((int)temp.size() == k && isSelfConjugate(temp)) {
                count++;
            }
            return;
        }
        if (parts <= 0 || remain <= 0) return;
        for (int val = min(maxVal, remain); val >= 1; --val) {
            current.push_back(val);
            generate(remain - val, parts - 1, val);
            current.pop_back();
        }
    };

    generate(n, k, n);
    return memo_recursive[key] = count;
}

// (ii) quy hoạch động
int p_selfcjg_dp(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (n < 0 || k <= 0) return 0;
    if (k > n) return 0;

    // dp[i][j] = số phân hoạch tự liên hợp của i có j phần
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;

    for (int sum = 1; sum <= n; ++sum) {
        for (int parts = 1; parts <= min(sum, k); ++parts) {
            int count = 0;
            vector<int> current;

            function<void(int,int,int)> generate = [&](int remain, int currParts, int maxVal) {
                if (currParts == 0 && remain == 0) {
                    vector<int> temp = current;
                    sort(temp.rbegin(), temp.rend());
                    if ((int)temp.size() == parts && isSelfConjugate(temp)) {
                        count++;
                    }
                    return;
                }
                if (currParts <= 0 || remain <= 0) return;
                for (int val = min(maxVal, remain); val >= 1; --val) {
                    current.push_back(val);
                    generate(remain - val, currParts - 1, val);
                    current.pop_back();
                }
            };

            generate(sum, parts, sum);
            dp[sum][parts] = count;
        }
    }

    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    memo_recursive.clear();
    int resRec = p_selfcjg_recursive(n, k);
    cout << "So phan hoach tu lien hop cua " << n << " co " << k << " phan (De quy): " << resRec;

    int resDP = p_selfcjg_dp(n, k);
    cout << "\nSo phan hoach tu lien hop cua " << n << " co " << k << " phan (DP): " << resDP;

    return 0;
}
