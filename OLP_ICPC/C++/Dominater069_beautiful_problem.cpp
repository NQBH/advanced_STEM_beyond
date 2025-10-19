#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    // x <= min or x >= max
    // min < x < max is bad
    // => in range if both smaller and larger exists, cooked
    // just spam smaller at one end, and larger at other end?
    // i <-> j if there exists interval covering both
    // if i <-> j, cannot have diff type on i and j
    // dp[i][number of 0s] = max number of 1s, but also need to know what is the last 0 / 1 position
    // we can extend last character always
    // we can extend other character only after some gap
    // prefmax?

    int n, m; cin >> n >> m;

    vector <int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    vector <int> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = c[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        for (int j = l; j <= r; j++) {
            b[j] = min(b[j], l);
            c[j] = max(c[j], r);
        }
    }

    // vector dp(n + 1, vector(n + 1, vector <int>(2, -INF)));
    // vector pref(n + 1, vector(n + 1, vector <int>(2, -INF)));
    int dp[n + 1][n + 1][2];
    int pref[n + 1][n + 1][2];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -INF;
                pref[i][j][k] = -INF;
            }
        }
    }

    dp[0][0][0] = dp[0][0][1] = 0;
    pref[0][0][0] = pref[0][0][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y < 2; y++) {
                for (int z = 0; z < 2; z++) {
                    if (y == z) {
                        int px = x - (y == 0);
                        if (px >= 0) {
                            dp[i][x][y] = max(dp[i][x][y], pref[i - 1][px][z] + (y == 1));
                        }
                    } else {
                        int px = x - (y == 0);
                        int lim = b[i] - 1;
                        if (px >= 0) {
                            dp[i][x][y] = max(dp[i][x][y], pref[lim][px][z] + (y == 1));
                        }
                    }
                }

                pref[i][x][y] = max(pref[i - 1][x][y], dp[i][x][y]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int lower = 0;
        int upper = 0;
        for (int j = 1; j < i; j++) lower += f[j];
        for (int j = i + 1; j <= n; j++) upper += f[j];

        if (pref[n][lower][0] >= upper || pref[n][lower][1] >= upper) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << "\n";
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}