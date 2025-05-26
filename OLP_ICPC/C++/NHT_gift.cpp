#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int lis(vector<int> &a, int k) {
    int n = a.size();
    vector<int> dp(n+5, INT_MAX); //lưu “điểm kết thúc nhỏ nhất” của mọi dãy con có độ dài cụ thể
    dp[0] = INT_MIN;
    int ans(0);

    for(int x : a) {
        int pos = upper_bound(dp.begin(), dp.begin() + ans + 1, x - k) - dp.begin();
        int L0 = pos - 1; // “độ dài tốt nhất” mà dãy con hiện tại có thể đạt trước khi thêm x
        dp[L0+1] = min(dp[L0 + 1], x);
        ans = max(ans, L0 + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cout << lis(a, k) << endl;
    }
    return 0;
}