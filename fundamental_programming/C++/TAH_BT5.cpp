#include <iostream>
using namespace std ;
int main () {
    long long a , b , x ;
    cin >> a >> b ;
    if (a == 0) {
        if (b == 0) {
            cout << "PT vo so nghiem";
        }
        else {cout << "PT vo nghiem";}
    }
    else {
        if ( b % a == 0) {
            long long x =  -b / a;
            cout << x ;
        }
        else {
            cout << "PT vo nghiem" ;
        }
    }
    return 0;
}
