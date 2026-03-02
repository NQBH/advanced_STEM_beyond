#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Vo so nghiem";
            else
                cout << "Vo nghiem";
        } else {
            cout << "Nghiem x = " << -c / b;
        }
    } else {
        double delta = b*b - 4*a*c;

        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2*a);
            double x2 = (-b - sqrt(delta)) / (2*a);
            cout << "Hai nghiem phan biet:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        } else if (delta == 0) {
            double x = -b / (2*a);
            cout << "Nghiem kep x = " << x;
        } else {
            cout << "Phuong trinh vo nghiem thuc";
        }
    }

    return 0;
}
