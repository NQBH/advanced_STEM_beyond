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
#define pops pop_back
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

int m,n,ans;

void moving(int x, int y, string s[]) {
    s[x][y] = '#';
    if (y > 0 && s[x][y-1] == '.') {
        ++ans;
        moving(x,y-1,s);
    }
    if (y < (m-1) && s[x][y+1] == '.') {
        ++ans;
        moving(x,y+1,s);
    }
    if (x > 0 && s[x-1][y] == '.') {
        ++ans;
        moving(x-1,y,s);
    }
    if (x < (n-1) && s[x+1][y] == '.') {
        ++ans;
        moving(x+1,y,s);
    }
}

void solve() {
    while (true) {
        ans = 1;
        cin >> m >> n;
        if ((n+m) == 0) {break;}
        int xp, yp;
        string s[n];
        frs(i, 0, n) {
            cin >> s[i];
            frs(j, 0, m) {
                if (s[i][j] == '@') {xp = i; yp = j;}
            }
        }
        moving(xp, yp, s);
        cout << ans << el
    }
}

SORAI {
    //Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/*
     /\__/\
    ( • 3• )
    / >♥️<\
*/

/*
6 9
...#..
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
