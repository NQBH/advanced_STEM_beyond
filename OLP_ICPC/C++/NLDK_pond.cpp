#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    int ans = 0, n, m;
    cin >> n >> m;
    vector<string> s(n);
    frs(i, 0, n) {cin >> s[i];}
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    frs(x, 0, n) {
        frs(y, 0, m) {
            if (!visited[x][y] && s[x][y] == 'W') {
                visited[x][y] = 1;
                deque<pair<int, int>> q;
                q.pb(mp(x, y));
                while (!q.empty()) {
                    int i = q[0].fi;
                    int j = q[0].se;
                    q.popf();
                    frs(k, 0, 8) {
                        int ti = i + dx[k];
                        int tj = j + dy[k];
                        if (ti >= 0 && ti < n && tj >= 0 && tj < m) {
                            if (!visited[ti][tj] && s[ti][tj] == 'W') {
                                visited[ti][tj] = 1;
                                q.pb(mp(ti, tj));
                            }
                        }
                    }
                }
                ++ans;
            }
        }
    }
    cout << ans << el
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
