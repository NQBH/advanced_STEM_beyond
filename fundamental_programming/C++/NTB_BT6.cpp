#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, delta;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;
    cout << "nhap c: ";
    cin >> c;
    delta = (pow(b, 2) - (4 * a * c));
    if (delta == 0) {
        cout << a << "x ^ 2 + " << b << "x + c = 0" << endl;
        cout << "nghiem kep x = " << -b / (2 * a) << endl;
    } else if (delta > 0) {
        cout << a << "x ^ 2 + " << b << "x + c = 0" << endl;
        cout << "x = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x = " << (-b + sqrt(delta)) / (2 * a) << endl;
    } else {
        cout << "vo nghiem" << endl;
    }
// bonus
    double thuc = -b / (2 * a);
    double ao = sqrt(-delta) / (2 * a);
    cout << "co 2 nghiem phuc" << endl;
    cout << "1: " << thuc << " + " << ao << "i" << endl;
    cout << "2: " << thuc << " - " << ao << "i" << endl;
}


