#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    const double EPS = 1e-9;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    if (fabs(a) > EPS) {
        double x = -b / a;
        cout << "Phuong trinh co 1 nghiem duy nhat:\n";
        cout << "x = " << x << endl;
    }
    else {
        if (fabs(b) < EPS) {
            cout << "Phuong trinh co vo so nghiem.\n";
        }
        else {
            cout << "Phuong trinh vo nghiem.\n";
        }
    }

    return 0;
}
