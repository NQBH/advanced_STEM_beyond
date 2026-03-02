#include <iostream>
using namespace std;
int main() {
    float a1, a2, b1, b2, c1, c2;
    cout << "nhap a1, b1, c1: "; cin >> a1 >> b1 >> c1;
    cout << "nhap a2, b2, c2: "; cin >> a2 >> b2 >> c2;
    cout << a1 << "x + " << b1 << "y = " << c1 << endl;
    cout << a2 << "x + " << b2 << "y = " << c2 << endl;
    // Phuong phap Cramer
    float D, Dx, Dy;
    D= (a1 * b2 - a2 * b1);
    Dx= (c1 * b2 - c2 * b1);
    Dy= (a1 * c2 - a2 * c1);
    if (!D) {
        if (!Dx && !Dy) cout << "phuong trinh co vo so nghiem" << endl;
        else cout << "phuong trinh vo nghiem" << endl;
    }
    else cout << "phuong trinh co nghiem duy nhat (x;y) = (" << Dx/D << ";" << Dy/D << ")" << endl;
}