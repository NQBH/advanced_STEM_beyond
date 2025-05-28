#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) { cin >> h[i]; }
    for (int i = 0; i < n; i++) { cin >> s[i]; }
    
    vector<int> dp(x + 1, -mod);
    // dp[i] : max page khi dung i tien 
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int cost = x; cost >= h[i]; cost--) {
            dp[cost] = max(dp[cost], dp[cost - h[i]] + s[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}