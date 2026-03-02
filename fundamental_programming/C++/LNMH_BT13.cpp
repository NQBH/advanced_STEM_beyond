#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n , m , M ; cin >> n >> m >> M ;
    double S = 0 ;
    for (int i = 1 ; i <= n ; i++) {
        double Sum = pow(i, m);
        if (S + Sum > M) break;
        S += Sum ;

    }
    cout << S ;
}