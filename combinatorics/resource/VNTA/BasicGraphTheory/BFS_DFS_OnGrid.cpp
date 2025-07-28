#include <bits/stdc++.h>
using namespace std;

/*
Input:
6 6
xxxooo
ooxooo
oxxxxo
ooooox
xxoxox
xoxxox
1 1 2 3
Output:
The number of connected components: 4
Yes. There is a path from (1,1) to (2,3)
*/

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void inp()  {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin>>a[i][j];
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int i, int j) {
    visited[i][j]=true;
    for(int d=0; d<4; d++) {
        int ni=i+dx[d];
        int nj=j+dy[d];
        if(ni>=1 && ni<=n && nj>=1 && nj<=m &&
           a[ni][nj]=='x' && !visited[ni][nj]) dfs(ni, nj);
    }
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j]=true;
    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();
        for(int d=0; d<4; d++) {
            int ni=top.first+dx[d];
            int nj=top.second+dy[d];
            if(ni>=1 && ni<=n && nj>=1 && nj<=m &&
               a[ni][nj]=='x' && !visited[ni][nj]) {
                    q.push({ni, nj});
                    visited[ni][nj]=true;
            }
        }
    }
}

void ConnectedComponent() {
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {
            if(a[i][j]=='x' && !visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout<<"\nThe number of connected components: "<<cnt;
}

void HasPath() {
    memset(visited, false, sizeof(visited));
    int si, sj, ei, ej;
    cin>>si>>sj>>ei>>ej;
    dfs(si, sj);
    if (!visited[ei][ej])
        cout<<"\nNo. There is no path from ("<<si<<','<<sj
        <<") to ("<<ei<<','<<ej<<")";
    else cout<<"\nYes. There is a path from ("<<si<<','<<sj
        <<") to ("<<ei<<','<<ej<<")";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    ConnectedComponent();
    HasPath();
}
