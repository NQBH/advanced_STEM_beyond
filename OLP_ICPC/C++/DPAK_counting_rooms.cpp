#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<string>a;
int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<bool>> check(1001, vector<bool>(1001, false));

void fill_in(int x, int y) {
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] == '.' && check[new_x][new_y] == false) {
            fill_in(new_x, new_y);
        }
    }
}

int main(){
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') continue;
            if (check[i][j] == false) {
                fill_in(i,j);
                cnt++;
            }            
        }
    }
    cout << cnt;
}