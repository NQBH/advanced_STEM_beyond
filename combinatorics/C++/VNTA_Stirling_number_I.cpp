#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = (i - 1) * f[i - 1][j] + f[i - 1][j - 1];
    cout << f[n][k];
}