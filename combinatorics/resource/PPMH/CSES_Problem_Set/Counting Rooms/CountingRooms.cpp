#include <bits/stdc++.h>

using namespace std;

char c;
int N, M, cnt;
int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
bool visted[1000][1000];

void dfs(int x, int y){
    visted[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + h[i], ny = y + v[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M && !visted[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %c", &c);
            visted[i][j] = (c == '#');
        }
    }

    for (int i = 0; i< N; i++){
        for(int j = 0; j < M; j++){
            if(!visted[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}