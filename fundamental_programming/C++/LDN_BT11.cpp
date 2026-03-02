#include <iostream>
using namespace std;
int main() {
    double a, b, c, A, B, C;
    cout << "Nhap he so a, b, c cua pt1: ";
    cin >> a >> b >> c;
    cout << "Nhap he so A, B ,C cua pt 2: ";
    cin >> A >> B >> c;
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0) {
        cout << "He co nghiem duy nhat: x = " << Dx / D << ", y = " << Dy / D << endl;
    } else if (Dx == 0 && Dy == 0) {
        cout << "He co vo so nghiem (VSN)" << endl;
    } else {
        cout << "He vo nghiem (VN)" << endl;
    }
}
