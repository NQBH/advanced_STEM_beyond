#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0) {
        if (a == b && b == c) {
            cout << "HLP" ;
        }
        else {
            cout << "HHCN" ;

            double DTXQ = 2 * (a * c + b * c) ;
            double DTTP = 2 * (a * b + b * c + c * a) ;
            double CHEO = sqrt(a * a + b * b + c * c);
            double V = a * b * c;

            cout << "Dien tich xung quanh cua HHCN la " << DTXQ << endl ;
            cout << "Dien tich toan phan cua HHCN la " << DTTP << endl ;
            cout << "Do dai duong cheo cua HHCN la " << CHEO << endl ;
            cout << "The tich cua HHCN la " << V << endl ;
        }
    }
    else {
        cout << -1 << endl ;
    }
}


