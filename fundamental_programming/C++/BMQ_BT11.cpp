#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c >> A >> B >> C;

    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He vo so nghiem";
        } else {
            cout << "He vo nghiem";
        }
    }
    return 0;
}
