#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c;
    cin >> A >> B >> C;

    double D = a * B - b * A;

    if (D != 0) {
        double x = (c * B - b * C) / D;
        double y = (a * C - c * A) / D;
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (a * B == b * A && c * B == b * C)
            cout << "He vo so nghiem";
        else
            cout << "He vo nghiem";
    }

    return 0;
}