#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

string s;
const ll N = 1000;
vector<vector<ll>> path(N, vector<ll>(N));

bool check(char c, char v) {
    return ((c == '(' && v == ')') || (c == '[' && v == ']'));
}

void display(ll i, ll j) {
    if (i > j) return;
    if (i == j) { // there is only 1 character for subsequence s[i, j]
        if (s[i] == '[' || s[i] == ']') cout << "[]";
        else cout << "()";
    }
    else if (path[i][j] == -1) { // s[i] & s[j] are matched brackets
        cout << s[i];
        display(i + 1, j - 1);
        cout << s[j];
    }
    else {
        display(i, path[i][j]);
        display(path[i][j] + 1, j);
    }
}

int main() {
    while (cin >> s) {
        ll n = s.size();
        if (n == 0) {
            printf("\n");
            continue;
        }
        s = " " + s; // 0-based indexing --> 1-based indexing
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INT_MAX));
        for (ll i = 1; i <= n; ++i) dp[i][i] = 1;
        for (ll r = 1; r <= n; ++r)
            for (ll l = r - 1; l >= 1; --l)
                if (check(s[l], s[r])) { // s[i] & s[j] are matched brackets
                    if (l == r - 1) dp[l][r] = 0;
                    else dp[l][r] = dp[l + 1][r - 1];
                    path[l][r] = -1;
                }
                else {
                    for (ll k = l; k < r; ++k)
                        if (dp[l][r] > dp[l][k] + dp[k + 1][r]) {
                            dp[l][r] = dp[l][k] + dp[k + 1][r];
                            path[l][r] = k;
                        }
                }
        cout << dp[1][n] << '\n';
        display(1, n);
        cout << '\n';
    }
}