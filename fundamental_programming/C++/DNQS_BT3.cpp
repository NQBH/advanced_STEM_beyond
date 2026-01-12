#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std ;
int main () {
    int a, b, c ;
    cin >> a ;
    cin >> b ;
    cin >> c ;

    if (a <= 0 || b <= 0 || c <= 0 ) {
        cout << "-1" ;
    }
    if ( a == b && b == c ) {
        cout << "HLP" ;
    }
    else {
        cout << "HHCN" << endl ;
        int Sxq = 2 * (a + b ) * c ;
        int Stp = 2 * (a * b + b * c + c * a) ;
        double duongcheo = sqrt(a * a + b * b + c * c);
        int thetich = a * b * c ;
        cout << "Dien tich xung quanh = " << Sxq << endl ;
        cout << "Dien tich toan phan =" << Stp << endl ;
        cout << "duong cheo = " << duongcheo << endl ;
        cout << "the tich = " << thetich << endl ;
    }
    return 0;
}