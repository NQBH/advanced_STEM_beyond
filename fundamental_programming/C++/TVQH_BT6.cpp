#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main () {
    cout << fixed << setprecision(2);
    double a, b , c ;
    cout << "nhap a: " ;
    cin >> a;
    cout << "nhap b: " ;
    cin >> b;
    cout << "nhap c: " ;
    cin >> c;
    if (a == 0 && b == 0 && c == 0 )
    {
        cout << "phuong trinh vo so nghiem" << endl ;
    }
    else if ( a == 0 && b == 0 && c != 0 )
    {
        cout << "phuong trinh vo nghiem" << endl ;
    }
    else if ( a == 0 && b != 0 )
    {
        double x = -c / b ;
        cout << "phuong trinh co nghiem duy nhat x = " << x << endl ;
    }
    else
    {
        double delta = b * b - 4 * a * c ;
        if ( delta < 0 )
        {
            cout << "phuong trinh vo nghiem" << endl ;
        }
        else if ( delta == 0 )
        {
            double x = -b / (2 * a) ;
            cout << "phuong trinh co nghiem kep x1 = x2 = " << x << endl ;
        }
        else
        {
            double x1 = ( -b + sqrt ( delta ) ) / ( 2 * a ) ;
            double x2 = ( -b - sqrt ( delta ) ) / ( 2 * a ) ;
            cout << "phuong trinh co hai nghiem phan biet: " << endl ;
            cout << "x1 = " << x1 << endl ;
            cout << "x2 = " << x2 << endl ;
        }
    }
    return 0 ;
}