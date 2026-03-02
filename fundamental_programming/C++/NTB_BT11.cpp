#include <bits/stdc++.h>
using namespace std;

int main() {
    double a,b,c;
    double A,B,C;
    cout << "giai pt tuyen tinh" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout  << "hpt co nghiem duy nhat: " << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx ==0 &&  Dy == 0) {
           cout << "hpt co vo so nghiem." << endl;
           cout << "hpt vo nghiem." << endl; 
        }
    }
    return 0;
}