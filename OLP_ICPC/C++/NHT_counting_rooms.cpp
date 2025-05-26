#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n, m, rooms;
bool check[1001][1001];
vector<ii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y)
{
    check[x][y] = true;
    for(auto p : directions)
        if(!check[x + p.first][y + p.second] && 
           x + p.first >= 0 && x + p.first < n &&
           y + p.second >= 0 && y + p.second < m)
                dfs(x + p.first, y + p.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j=0; j < m; ++j)
        {
            char c;
            cin >> c;
            if(c == '#') check[i][j] = true;
        }
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(!check[i][j])
            {
                dfs(i, j);
                ++rooms;
            }
        }
    
    cout << rooms << '\n';
    return 0;
}