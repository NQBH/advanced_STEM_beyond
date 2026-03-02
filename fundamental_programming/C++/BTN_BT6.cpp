#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) cout << (c == 0 ? "Vo so nghiem" : "Vo nghiem");
        else cout << "x = " << -c / b;
    } else {
        double d = b * b - 4 * a * c;
        if (d < 0) cout << "Vo nghiem";
        else if (d == 0) cout << "Nghiem kep x = " << -b / (2 * a);
        else {
            cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(d)) / (2 * a);
        }
    }
    return 0;
}