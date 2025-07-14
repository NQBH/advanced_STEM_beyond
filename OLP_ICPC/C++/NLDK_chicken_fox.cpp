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
#define mp make_pair
#define popf pop_front
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    int n, m, fox = 0, chicken = 0;
    cin >> n >> m;
    string s[n];
    frs(i, 0, n) {cin >> s[i];}
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    frs(i, 0, n) {
        frs(j, 0, m) {
            if (!visited[i][j] && s[i][j] != '#') {
                int f = 0, c = 0;
                deque<pair<int, int>> q;
                q.pb(mp(i, j));
                visited[i][j] = 1;
                while (!q.empty()) {
                    int x = q[0].fi;
                    int y = q[0].se;
                    q.popf();
                    if (s[x][y] == 'f') {++f;}
                    if (s[x][y] == 'c') {++c;}
                    frs(z, 0, 4) {
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (!visited[nx][ny] && s[nx][ny] != '#') {
                                q.pb(mp(nx, ny));
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                }
                if (f >= c) {fox += f;}
                else {chicken += c;}
            }
        }
    }
    cout << fox << " " << chicken;
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
