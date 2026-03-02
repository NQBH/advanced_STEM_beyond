#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Vo so nghiem";
            else
                cout << "Vo nghiem";
        } else {
            cout << -c / b;
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            cout << (-b + sqrt(delta)) / (2 * a) << '\n';
            cout << (-b - sqrt(delta)) / (2 * a);
        }
        else if (delta == 0) {
            cout << -b / (2 * a);
        }
        else {
            double thuc = -b / (2 * a);
            double ao = sqrt(-delta) / (2 * a);
            cout << thuc << " + " << ao << "i\n";
            cout << thuc << " - " << ao << "i";
        }
    }
}