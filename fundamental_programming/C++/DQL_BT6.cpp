#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuowng trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            float x = -c / b;
            cout << "Phuong trinh co 1 nghiem: x = " << x;
        }
    } else {
        float delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem";
        } else if (delta == 0) {
            float x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x;
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        }
    }

    return 0;
}