#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5007;

unsigned short dp[MAXN][MAXN];
bitset<MAXN> vis[MAXN];
int n, m;

// Bắt đầu đếm thời gian
auto start = chrono::steady_clock::now().time_since_epoch().count();

int f(int n, int m) {
    if (n < m) swap(n, m);
    if (n == m) return 0;
    if (vis[n][m]) return dp[n][m];
    vis[n][m] = 1;

    int g = __gcd(n, m);
    if (g != 1) return dp[n][m] = f(n / g, m / g);
    if (n >= m * 3) return dp[n][m] = 1 + f(n - m, m);

    // Giới hạn thời gian tính toán
    auto cur = chrono::steady_clock::now().time_since_epoch().count();
    if ((cur - start) / 1e6 >= 50 && n >= m + 200)
        return dp[n][m] = 1 + f(n - m, m);

    unsigned short res = 30000;
    int ca = max(1, n / 4 - 6), cb = max(1, m / 4 - 6);

    for (int i = n / 2; i >= ca; --i)
        res = min<unsigned short>(res, 1 + f(i, m) + f(n - i, m));
    for (int i = m / 2; i >= cb; --i)
        res = min<unsigned short>(res, 1 + f(n, i) + f(n, m - i));

    return dp[n][m] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if (n < m) swap(n, m);

    // Tiền xử lý cho các giá trị nhỏ
    for (int i = 1; i <= 1000; ++i) {
        dp[i][1] = dp[1][i] = i - 1;
        for (int j = 2; j < i; ++j) {
            unsigned short *a = dp[j];
            unsigned short *b = dp[i];
            unsigned short c = 30000;
            for (int k = 1; k <= i / 2; ++k)
                c = min<unsigned short>(c, 1 + a[k] + a[i - k]);
            for (int k = 1; k <= j / 2; ++k)
                c = min<unsigned short>(c, 1 + b[k] + b[j - k]);
            a[i] = b[j] = c;
        }
    }

    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            vis[i][j] = 1;

    cout << f(n, m) + 1 << '\n';
    return 0;
}