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

int dx[8] = { -1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

void solve() {
    int cases = 1;
    vector<vector<bool>> shui;
    vector<vector<bool>> visited1;
    vector<vector<bool>> visited2;
    while (true) {
        int n, m, sea = 0, check = 0, total = 0;
        cin >> n >> m;
        if ((n + m) == 0) {break;}
        vector<vector<int>> a(n, vector<int> (m));
        frs(i, 0, n) {
            frs(j, 0, m) {
                cin >> a[i][j];
            }
        }
        shui.clear();
        shui.resize(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        while (check == 0) {
            int counter = 0;
            visited1.clear();
            visited1.resize(n, vector<bool> (m, 0));
            frs(i, 0, n) {
                frs(j, 0, m) {
                    if (!visited1[i][j] && a[i][j] <= sea) {
                        if (i == 0 || j == 0 || i == (n - 1) || j == (m - 1)) {
                            if (shui[i][j] == 0) {
                                shui[i][j] = 1;
                                ++total;
                            }
                            q.push(mp(i, j));
                            visited1[i][j] = 1;
                            while (!q.empty()) {
                                int x = q.front().fi;
                                int y = q.front().se;
                                q.pop();
                                frs(k, 0, 4) {
                                    int nx = x + dx[k];
                                    int ny = y + dy[k];
                                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                        if (!visited1[nx][ny] && a[nx][ny] <= sea) {
                                            if (shui[nx][ny] == 1) {
                                                visited1[nx][ny] = 1;
                                                q.push(mp(nx, ny));
                                            } else {
                                                shui[nx][ny] = 1;
                                                ++total;
                                                visited1[nx][ny] = 1;
                                                q.push(mp(nx, ny));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (total >= (n * m)) {break;}
            visited2.clear();
            visited2.resize(n, vector<bool> (m, 0));
            frs(i, 0, n) {
                frs(j, 0, m) {
                    if (!shui[i][j] && !visited2[i][j]) {
                        if (counter == 1) {
                            check = 1;
                            i = n;
                            break;
                        }
                        visited2[i][j] = 1;
                        q.push(mp(i, j));
                        while (!q.empty()) {
                            int x = q.front().fi;
                            int y = q.front().se;
                            q.pop();
                            frs(k, 0, 4) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                    if (!visited2[nx][ny] && !shui[nx][ny]) {
                                        visited2[nx][ny] = 1;
                                        q.push(mp(nx, ny));
                                    }
                                }
                            }
                        }
                        ++counter;
                    }
                }
            }
            ++sea;
        }
        if (check) {cout << "Case " << cases << ": Island splits when ocean rises " << (sea - 1) << " feet." << el}
        else {cout << "Case " << cases << ": Island never splits." << el}
        ++cases;
    }
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
