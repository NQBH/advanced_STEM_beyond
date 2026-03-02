#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a == 0 && b == 0) {
        cout << "Phuong trinh vo so nghiem";
    }
    else if (a == 0 && b != 0) {
        cout << "Phuong trinh vo nghiem";
    }
    else {
        cout << "Nghiem x = " << -b / a;
    }

    return 0;
}
