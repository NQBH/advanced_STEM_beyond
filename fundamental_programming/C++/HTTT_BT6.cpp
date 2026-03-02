#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "Phuong trinh vo nghiem";
    } else if (delta == 0) {
        cout << "Phuong trinh co nghiem kep: x = " << -b / (2 * a);
    } else {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    }

    return 0;
}