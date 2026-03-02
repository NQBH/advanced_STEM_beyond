#include <iostream>
using namespace std;
int main() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c;
    cin >> A >> B >> C;
    double D = a * B - b * A;
    double Dx = c * B - b * C;
    double Dy = a * C - c * A;
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0)
            cout << "He vo so nghiem";
        else
            cout << "He vo nghiem";
    }
}
