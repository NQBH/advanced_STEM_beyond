#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G=<V,E> được biểu diễn dưới dạng ma trận kề.
Chuyển đổi biểu diễn đồ thị dưới dạng danh sách cạnh
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, u, v;
    cin>>n;
    int a[n+1][n+1];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin>>a[i][j];
    }

    //Solution 1
    cout<<"--Print directly--\n";
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++)
            if (a[i][j]==1) cout<<i+1<<' '<<j+1<<'\n';
    }

    //Solution 2
    cout<<"--Use the vector Edge--\n";
    vector<pair<int, int>> e;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j]==1) e.push_back({i+1, j+1});
        }
    }
    for(int i=0; i<e.size(); i++) cout<<e[i].first<<' '<<e[i].second<<'\n';
}
