#include <bits/stdc++.h>
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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char movement[4] = {'U', 'L', 'R', 'D'};
vector<vector<char>> path(1009, vector<char> (1009, '.'));

void solve() {
    int n, m, xA, yA, ans = 0;
    cin >> n >> m;
    string c[n];
    bool Anotfound = 1;
    frs(i, 0, n) {
        cin >> c[i];
        if (Anotfound) {
            frs(j, 0, m) {
                if (c[i][j] == 'A') {
                    xA = i; yA = j;
                    path[i][j] = 'A';
                    Anotfound = 0;
                    break;
                }
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(mp(xA, yA));
    c[xA][yA] = '#';
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        frs(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (c[nx][ny] == '#') {continue;}
                elif (c[nx][ny] == '.') {
                    c[nx][ny] = '#';
                    q.push(mp(nx, ny));
                    path[nx][ny] = movement[i];
                } else {
                    cYES
                    path[nx][ny] = movement[i];
                    string p;
                    while (path[nx][ny] != 'A') {
                        p += path[nx][ny];
                        ++ans;
                        if (path[nx][ny] == 'U') {++nx;}
                        elif (path[nx][ny] == 'L') {++ny;}
                        elif (path[nx][ny] == 'R') {--ny;}
                        else {--nx;}
                    }
                    reverse(all(p));
                    cout << ans << el
                        cout << p << el
                        ret
                }
            }
        }
    }
    cNO
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
