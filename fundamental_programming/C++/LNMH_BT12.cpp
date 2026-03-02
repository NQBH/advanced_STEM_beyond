#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n , m ; cin >> n >> m ;
    double Sum = 0 ;
    for (int i = 1 ; i <= n ; i++)
        Sum += pow(i, m);
    cout << Sum ;
}