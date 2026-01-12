#include <iostream>    
using namespace std ;
int main ()
{
    double a ;
    cout << "Do dai canh hinh chu nhat: "  ;
    cin >> a;
    double b ;
    cout << "Nhap chieu rong hinh chu nhat: "  ;
    cin >> b;
    double S = a * b ;
    cout << "Dien tich hinh chu nhat la: " << S << endl ;
    double P = 2 * (a + b) ;
    cout << "Chu vi hinh chu nhat la: " << P << endl ;
    double d = sqrt(a * a + b * b) ;
    cout << "Do dai duong cheo hinh chu nhat la: " << d << endl ;
    return 0 ;  
}
