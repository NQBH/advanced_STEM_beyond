#include <iostream>
using namespace std;

int main() {
    // Khai bao 2 bien a va b
    float a, b;

    // Nhap du lieu
    cout << "Nhap he so a: ";
    cin >> a;

    cout << "Nhap he so b: ";
    cin >> b;

    // Giai phuong trinh ax + b = 0
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem";
        } else {
            cout << "Phuong trinh vo nghiem";
        }
    } else {
        float x;
        x = -b / a;
        cout << "Phuong trinh co nghiem x = " << x;
    }

    return 0;
}
