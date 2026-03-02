#include <bits/stdc++.h>
using namespace std;

int main(){
    long long m,n,temp; cin >> m >> n;
    long long Sm = 0;
    for (int i = 1; i <= n; ++i ){
        temp = 1;
        for (int j = 1; j <= m; j++){
            temp *= i;
        }
        Sm += temp;
    }
    cout << Sm;
}