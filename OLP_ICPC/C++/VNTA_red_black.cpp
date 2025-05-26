#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int w, h;
vector<string> a;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return (x>=0 && x<h && y>=0 && y<w && !visited[x][y] && a[x][y]=='.');
}

int dfs(int x, int y) {
    visited[x][y]=true;
    int cnt=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (isValid(nx, ny)) {
            cnt+=dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    KhangGPT40_TramAnhGrok3;
    while (true) {
        cin>>w>>h;
        if (w==0 && h==0) break;
        a.assign(h, "");
        for (int i=0; i<h; i++) {
            cin>>a[i];
        }

        int sX, sY;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (a[i][j]=='@') {
                    sX=i;
                    sY=j;
                    break;
                }
            }
        }
        visited.assign(h, vector<bool>(w, false));
        int res=dfs(sX, sY);
        cout<<res<<"\n";
    }
    return 0;
}
/*
6 9
...#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
*/
