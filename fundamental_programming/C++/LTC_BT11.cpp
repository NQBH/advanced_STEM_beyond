#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    double D, Dx, Dy;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;
    cout << "Nhap A B C: ";
    cin >> A >> B >> C;
    D  = a * B - A * b;
    Dx = c * B - C * b;
    Dy = a * C - A * c;
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem";
        }
        else {
            cout << "He vo nghiem";
        }
    }
    return 0;
}
