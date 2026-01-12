#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, delta;
    cin >> a >> b >> c;
    delta = (pow(b, 2) - (4 * a * c));
    if (delta == 0) {
        cout << a << "x^2 + " << b << "x + c = 0" << '\n';
        cout << "Nghiem kep x = " << -b / (2 * a) << '\n';
    } else if (delta > 0) {
        cout << a << "x^2 + " << b << "x + c = 0" << '\n';
        cout << "x = " << (-b + sqrt(delta)) / (2 * a) << '\n';
        cout << "x = " << (-b - sqrt(delta)) / (2 * a) << '\n';
    } else {
        cout << "vo nghiem" << '\n';
    }
}