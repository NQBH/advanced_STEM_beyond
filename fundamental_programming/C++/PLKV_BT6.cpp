#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhap a:";
    cin >> a;
    cout << "Nhap b:";
    cin >> b;
    cout << "Nhap c:";
    cin >> c;


    if (a == 0) {
        // Phuong trinh bac 1
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            double x = -c / b;
            cout << "Phuong trinh co 1 nghiem: x = " << x;
        }
    } else {
        // Phuong trinh bac 2
        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << '\n';
            cout << "x2 = " << x2;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x;
        } else {
            cout << "Phuong trinh vo nghiem";
        }
    }

    return 0;
}