#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n ; cin >> n ;
    int so0 ;
    int soam ;
    int soduong ;
    double a ;
    for (int i = 0 ; i <= n ; i++) {
        if (a == 0) so0++ ;
        else if (a < 0) soam++ ;
        else soduong++;
    }
    cout <<  "tong so 0 :" << so0 << endl ;
    cout <<  "tong so am :" << soam << endl;
    cout <<  "tong so duong :" << soduong << endl;
}