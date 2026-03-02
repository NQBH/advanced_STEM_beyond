#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main () {
    double a, b ;
    cout << "nhap a: " ;
    cin >> a;
    cout << "nhap b: " ;
    cin >> b;
    cout << fixed << setprecision(2);
    if (a == 0 && b == 0) {
        cout << "phuong trinh vo so nghiem" << endl ;
    } else if (a == 0 && b != 0) {
        cout << "phuong trinh vo nghiem" << endl ;
    }
    else {
        double x = -b / a ;
        cout << "phuong trinh co nghiem duy nhat x = " << x << endl ;
    }
    return 0 ;
}
