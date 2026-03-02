#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cout << "Nhap he so a cua pt1: " << '\n';
    cin >> a;
    cout << "Nhap he so b cua pt1: " << '\n';
    cin >> b;
    cout << "Nhap he so c cua pt1: " << '\n';
    cin >> c;
    cout << "Nhap he so A cua pt2: " << '\n';
    cin >> A;
    cout << "Nhap he so B cua pt2: " << '\n';
    cin >> B;
    cout << "Nhap he so C cua pt2: " << '\n';
    cin >> C;

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        cout << "nghiem duy nhat x = " << Dx / D << ", y = " << Dy / D << '\n';
    } else if (Dx == 0 && Dy == 0) {
        cout << "vo so nghiem" << '\n';
    } else {
        cout << "vo nghiem " << '\n';
    }
    return 0;
}
