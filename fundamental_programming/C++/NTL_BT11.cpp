#include <iostream>
using namespace std;
int main() {
    double a, b, c, A, B, C;
    cout << "Nhap a, b, c (pt1): ";
    cin >> a >> b >> c;
    cout << "Nhap A, B, C (pt2): ";
    cin >> A >> B >> C;

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        cout << "nghiem duy nhat: x = " << Dx / D 
             << ", y = " << Dy / D;
    } 
    else if (Dx == 0 && Dy == 0) {
        cout << "vo so nghiem";
    } 
    else {
        cout << "vo nghiem";
    }
