#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Khai bao cac bien
    float a, b, c;
    float delta, x1, x2;

    // Nhap du lieu
    cout << "Nhap he so a: ";
    cin >> a;

    cout << "Nhap he so b: ";
    cin >> b;

    cout << "Nhap he so c: ";
    cin >> c;

    // Xu ly
    if (a == 0) {
        // Phuong trinh bac 1: bx + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem";
            } else {
                cout << "Phuong trinh vo nghiem";
            }
        } else {
            cout << "Phuong trinh co 1 nghiem x = " << -c / b;
        }
    } else {
        // Phuong trinh bac 2
        delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem";
        } 
        else if (delta == 0) {
            x1 = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep x = " << x1;
        } 
        else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "Phuong trinh co 2 nghiem:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        }
    }

    return 0;
}
