#include <bits/stdc++.h>
using namespace std;
/*
(\_/)
( * *)
 / ?? <3
*/
void IOfile()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen("b.inp","r",stdin);
    freopen("b.out","w",stdout);
}
int n,m;
char r[1010][1010];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int g;
bool DFS(int i,int j)
{
    r[i][j]='#';
    g++;
    //if (g < 30) cout <<i<<" "<<j<<endl;
    for (int k=0;k<4;k++)
        if (r[dx[k]+i][dy[k]+j]=='.')
        DFS(dx[k]+i,dy[k]+j);
    return false;
}
int main()
{
    //IOfile();
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    cin >> r[i][j];
    int cnt=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        if (r[i][j] == '.')
        {
            DFS(i,j);
            cnt++;
        }
    cout << cnt;
	return 0;
}