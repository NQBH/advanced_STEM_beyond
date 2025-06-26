#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<vector<int>> pk(MAXN, vector<int>(MAXN, 0));

//p_k(n)
void solve(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 && j == 0) pk[0][0] = 1;
            else if (j == 0 || j > i) pk[i][j] = 0;
            else pk[i][j] = pk[i - 1][j - 1] + pk[i - j][j];
        }
    }
}

//p(n)
long long p(int n) {
    long long res = 0;
    for (int i = 0; i <= n; ++i) res += pk[n][i];
    return res;
}

long long partition_empty(int n, int k) {
    int ans = 0;
    for (int i = 0; i <= k; ++i) ans += pk[n][i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    solve(n);
    cout << "p(n) = " << p(n) << "\n========\n";
    cout << "pk(n):\n";
    for (int i = 0; i <= n; ++i) cout << "p_" << i << "(" << n << ") = " << pk[n][i] << '\n';
    for (int i = 0; i <= n; ++i) cout << "partition of " << n << "objects into " << i << " possibly empty boxes = " << partition_empty(n, i) << '\n';
    return 0;
}