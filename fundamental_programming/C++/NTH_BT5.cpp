#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    double a, b;
    cout << "--- Chuong trinh giai phuong trinh ax + b = 0 ---" << endl;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    } else {
        double x = -b / a;
        cout << "Phuong trinh co nghiem duy nhat: x = " << x << endl;
    }

    return 0;
}