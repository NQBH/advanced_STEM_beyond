#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c >> A >> B >> C;
    double x, y;
    y = (c * B - b * C) / (a * B - b * A);
    x = (c - (b * y)) / a;
    if (a * B - A * b != 0) {
        cout << "He co 1 nghiem duy nhat:\n";
        cout << "x = " << x << ", y = " << y << endl;
    } else {
        if (c * B - C * b == 0 && a * C - A * c == 0) {
            cout << "He co vo so nghiem" << endl;
        } else {
            cout << "He vo nghiem" << endl;
        }
    }
    return 0;
}