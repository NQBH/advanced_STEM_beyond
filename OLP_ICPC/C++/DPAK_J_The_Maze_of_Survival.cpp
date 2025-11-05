#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1,-1, 0, 0};

struct point {
    int x, y;
};

struct path {
    point p;
    int hp;
    int move;
};

signed main() {
    int r, c; cin >> r >> c;
    vector<vector<char>> a(r + 1, vector<char>(c + 1));
    point s, d;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s.x = i;
                s.y = j;
            }
            if (a[i][j] == 'D') {
                d.x = i; d.y = j;
            }
        }
    }
    bool visited[105][105][5];
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k < 5; k++) {
                visited[i][j][k] = false;
            }
        }
    }
    visited[s.x][s.y][0] = true;

    queue<path> q;
    q.push({s, 0, 0});
    
    while (q.empty() == false) {
        auto [curP, curHp, curMove] = q.front();
        q.pop();
        int x = curP.x, y = curP.y;
        if (a[x][y] == 'D') {
            cout << curMove;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;
            if (new_x <= r && new_y <= c && new_x >= 1 && new_y >= 1 && visited[new_x][new_y][curHp] == false) {
                point newP;
                newP.x = new_x; newP.y = new_y;
                if (a[new_x][new_y] == '+') {
                    if (curHp + 1 >= 3) continue;
                    q.push({newP, curHp + 1, curMove + 1});
                    visited[new_x][new_y][curHp + 1] = true;
                }
                else {
                    q.push({newP, curHp, curMove + 1});
                    visited[new_x][new_y][curHp] = true;
                }
            } 
        }
    }
    cout << -1;
}
