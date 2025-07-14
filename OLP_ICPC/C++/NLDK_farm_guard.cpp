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
 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    frs(i, 0, n)
        frs(j, 0, m)
            cin >> a[i][j];
    vector<vector<bool>> visited(n, vector<bool> (m, 0));
    frs(i, 0, n) {
        frs(j, 0, m) {
            if (!visited[i][j] && a[i][j] > 0) {
                visited[i][j] = 1;
                int temp = 1, val = a[i][j];
                queue<pair<int, int>> q;
                q.push(mp(i, j));
                while (!q.empty()) {
                    int ti = q.front().fi;
                    int tj = q.front().se;
                    q.pop();
                    int check = 1;
                    frs(k, 0, 8) {
                        int nx = ti + dx[k];
                        int ny = tj + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (a[nx][ny] > 0) {
                                if (a[nx][ny] > a[ti][tj]) {check = 0;}
                                if (!visited[nx][ny] && a[nx][ny] == val) {q.push(mp(nx, ny)); visited[nx][ny] = 1;}
                            }
                        }
                    }
                    if (!check) {temp = 0;}
                }
                ans += temp;
            }
        }
    }
    cout << ans;
}
 
SORAI {
    Sanic_speed
    //int t = 1; cin >> t;
    //wh(t) {solve();}
    solve();
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
