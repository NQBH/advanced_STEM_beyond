#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n, m, sx, sy, ex, ey;
bool check[1001][1001];
vector<vector<ii>> path;
vector<ii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs()
{
    queue<ii> q;
    q.push({sx, sy});
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(auto dr : directions)
        {
            int nx = cx + dr.first;
            int ny = cy + dr.second;
            if(!check[nx][ny] && 
                nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                check[nx][ny] = true;
                path[nx][ny] = dr; 
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    path.resize(n);
    for(int i = 0; i < n; ++i)
        path[i].resize(m);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            path[i][j] = {-1, -1};
            char c;
            cin >> c;
            if(c == '#') check[i][j] = true;
            if(c == 'A') sx = i, sy = j;
            if(c == 'B') ex = i, ey = j;
        }
    bfs();

    if(!check[ex][ey])
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<ii> ans;
    ii cur = {ex, ey};
    while(cur.first != sx || cur.second != sy)
    {
        ans.push_back(path[cur.first][cur.second]);
        cur.first -= ans.back().first;
        cur.second -= ans.back().second;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &p : ans)
    {
        if(p.first == 1 && p.second == 0) cout << 'D';
        else if(p.first == -1 && p.second == 0) cout << 'U';
        else if(p.first == 0 && p.second == 1) cout << 'R';
        else if(p.first == 0 && p.second == -1) cout << 'L';
    }

    return 0;
}