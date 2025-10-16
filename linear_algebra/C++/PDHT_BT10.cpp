#include <bits/stdc++.h>
#define for(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main(){
    vector <vector<int> > a(2,vector<int>(2));
    for(i,2)
        for(j,2)
            cin >> a[i][j];
    cout <<"detA= " << a[0][0]*a[1][1] - a[1][0]*a[0][1];
}