#include <iostream>
#include <cmath>
using namespace std;

int main () {
    double a, b, c;
    cout << "nhap a, b, c: " << endl;
    cin >> a >> b >> c;

    if (a == 0) {
        //bx + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "Vo so nghiem" << endl;

            } else cout << "Vo nghiem" << endl;
        } else cout << "x = " << -c / b << endl;

    } else {
        double D = (b * b) - (4 * a * c);
        if ( D > 0 ) {
            cout << "2 nghiem thuc" << endl;
            cout << "x = " << ( -b + sqrt(D) ) / (2 * a) << endl;
            cout << "x = " << ( -b - sqrt(D) ) / (2 * a) << endl;
        } else if ( D == 0 ) {
            cout << "nghiem kep" << endl;
            cout << "x = " << ( -b ) / ( 2 * a ) << endl;
        } else {

            double thuc =  ( -b ) / ( 2 * a );
            double ao = sqrt( -D ) / ( 2 * a );

            cout << "x = " << thuc << " + " << ao << "i" << endl;
            cout << "x = " << thuc << " - " << ao << "i" << endl;
        }


    }



}