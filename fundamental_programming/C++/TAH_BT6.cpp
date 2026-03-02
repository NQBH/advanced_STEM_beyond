#include <bits/stdc++.h>
using namespace std ;
int main () {
    long long a , b , c, delta , x1 , x2 ;
    cin >> a >> b >> c ;
    float(delta = b * b - 4 * a * c);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "PT vo so nghiem";
            }
            else {cout << "PT vo nghiem";}
        }
    }
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "PT có 2 nghiem phan biet";
        cout << "x1 =" << x1 ;
        cout << "x2 =" << x2 ;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << " PT có nghiem kep x1 =x2 =" << x1 << x2;
    } else {
        cout << "PT vo nghiem thuc";
    }
}

