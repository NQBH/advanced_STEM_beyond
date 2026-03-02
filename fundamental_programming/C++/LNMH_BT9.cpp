#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n, a ; cin >> n ;
    int tongchan = 0 ; int tongle = 0 ;
    for (int i = 0 ; i <= n ; i++) {
        cin >> a ;
        if (a % 2 == 0)
            tongchan ++ ;
        else
            tongle ++;

    }


    cout << tongchan << " " << tongle << endl ;
    return 0;
}


