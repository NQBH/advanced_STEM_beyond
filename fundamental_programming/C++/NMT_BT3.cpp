#include <iostream>
#include <math.h>
using namespace std;
int main () {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a == c) {
        cout << " HLP " << '\n';
    }
    else {
        if ( a > 0  && b > 0 && c > 0) {
            cout << " HHCN " << '\n';
            // tinh dien tich xung quanh HHCN
            float sxq = ( a + b) * 2 * c;
            cout << " dien tich xung quanh HHCN " << a << b << c << " bang " << sxq << '\n';
            // tinh dien tich toan phan HHCN
            float stp = ( a + b) * 2 * c + 2 * a * b;
            cout << " dien tich toan phan HHCN " << a << b << c << " bang " << stp << '\n';
            // tinh the tich HHCN
            float V = a * b * c;
            cout << " the tich HHCN " << a << b << c << " bang " << V << '\n';
            // tinh duong cheo HHCN
            double d = sqrt( a * a + b * b + c * c);
            cout << " duong cheo HHCN " << a << b << c << " bang " << d << '\n';
        }
        else {
            cout << -1;
        }
    }
    return 0;
}