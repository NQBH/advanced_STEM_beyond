#include <bits/stdc++.h>
using namespace std;

const int MAX=1000;
int n, m;
vector<string> grid;
bool visited[MAX][MAX];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x, int y) {
    visited[x][y]=true;
    for(int d=0; d<4; d++) {
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx>=0 && nx<n && ny>=0 && ny<m &&
           grid[nx][ny]=='.' && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    int res=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='.'&&!visited[i][j]) {
                dfs(i,j);
                res++;
            }
        }
    }
    cout<<res;
}
