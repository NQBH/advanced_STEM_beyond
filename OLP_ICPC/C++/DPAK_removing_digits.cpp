#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mod = 1e9 + 7;

vector<int> get_digits(int n) {
    vector<int> digits;
    while(n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}
int main(){
    int n; cin >> n;
    // dp[i] : so cach thap nhat dat i
    vector<int> dp(n + 1, mod);
    dp[n] = 0;
    for (int i = n; i >= 0; i--) {
        vector<int> digits = get_digits(i);
        for (auto d : digits) {
            dp[i - d] = min(dp[i] + 1, dp[i - d]);
        }
    }
    cout << dp[0];
}