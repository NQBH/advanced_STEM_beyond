#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int MAX=100;
int n, m;
vector<vector<int>>L(MAX,vector<int>(MAX,0)); //Laplacian matrix

//tính định thức ma trận nxn bằng cách đưa về ma trận tam giác trên
ld determinant(vector<vector<ld>>mat, int n) {
    ld det=1;
    for (int i=0; i<n; ++i) {
        int pivot=i;
        while (pivot<n && fabs(mat[pivot][i])<1e-9) pivot++;
        if (pivot==n) return 0; //cột i toàn phần tử = 0
        if (pivot!=i) {
            swap(mat[i],mat[pivot]);
            det*=-1; //đổi chỗ 2 dòng, det đổi dấu
        }
        det*= mat[i][i]; //nhân phần tử trên đường chéo chính
        //khử gauss
        for (int j=i+1; j<n; ++j) {
            ld r=mat[j][i]/mat[i][i];
            for (int k=i; k<n; ++k)
                mat[j][k]-=r*mat[i][k];
        }
    }
    return round(det);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m; //số đỉnh, số cạnh
    vector<pair<int, int>> edges(m);
    /*
    L=D-A nên ta có:
    L[i][j]= bậc của đỉnh i nếu i=j
    L[i][j]=-1 nếu i!=j và có cạnh (i,j)
    L[i][j]=0 nếu i!=j và không có cạnh (i,j)
    */
    for (int i=0; i<m; ++i) {
        int u, v;
        cin>>u>>v;
        u--; v--; //chuyển về 0-idx
        edges[i]={u,v};
        L[u][u]++;
        L[v][v]++;
        L[u][v]--;
        L[v][u]--;
    }

    //tạo ma trận Lminor (bỏ dòng 0, cột 0 trong L)
    vector<vector<ld>> mat(n-1, vector<ld>(n-1));
    for (int i=1; i<n; ++i)
        for (int j=1; j<n; ++j)
            mat[i-1][j-1]=L[i][j];

    //tổng số spanning tree (undirected graph)
    cout<<(long long)determinant(mat, n-1);
    return 0;
}

/*
Input: Prob 1.3
7 12
1 2
1 3
1 4
1 6
2 4
2 5
2 7
3 6
4 6
4 7
5 7
6 7
Output: 288
*/
