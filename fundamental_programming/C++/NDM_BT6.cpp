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

    cout << "Phuong trinh: " << a << "x^2 + " << b << "x + " << c << " = 0\n";

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            cout << "Phuong trinh co mot nghiem: x = " << -c / b;
        }
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        cout << "Phuong trinh co hai nghiem phan biet\n";
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    }
    else if (delta == 0) {
        cout << "Phuong trinh co nghiem kep\n";
        cout << "x = " << -b / (2 * a);
    }
    else {
        double thuc = -b / (2 * a);
        double ao = sqrt(-delta) / (2 * a);

        cout << "Phuong trinh co hai nghiem phuc\n";
        cout << "x1 = " << thuc << " + " << ao << "i\n";
        cout << "x2 = " << thuc << " - " << ao << "i\n";
    }

    return 0;
}
