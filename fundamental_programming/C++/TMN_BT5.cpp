#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem";
        } else {
            cout << "Phuong trinh vo nghiem";
        }
    } else {
        float x = -b / a;
        cout << "Phuong trinh co nghiem x = " << x;
    }

    return 0;
}