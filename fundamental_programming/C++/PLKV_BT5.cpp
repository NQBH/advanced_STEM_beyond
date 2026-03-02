#include <iostream>
#include <cmath>
using namespace std;

int main() {
//prolem 5
    float a, b;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh vo so nghiem";
        else
            cout << "Phuong trinh vo nghiem";
    } else {
        float x = -b / a;
        cout << "Nghiem x = " << x;
        return 0;
    }
}