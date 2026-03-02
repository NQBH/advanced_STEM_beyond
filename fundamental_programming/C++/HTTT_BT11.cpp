#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    cout << "Nhap A, B, C: ";
    cin >> A >> B >> C;


    double D = a * B - A * b;
    double Dx = c * B - b * C;
    double Dy = a * C - c * A;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem\n";
        } else {
            cout << "He vo nghiem\n";
        }
    }

    return 0;
}