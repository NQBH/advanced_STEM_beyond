#include <iostream>
using namespace std;

int main() {
    float a, b, c, A, B, C;
    cout << "Nhap a, b, c: "; cin >> a >> b >> c;
    cout << "Nhap A, B, C: "; cin >> A >> B >> C;

    float D = a * B - A * b;
    float Dx = c * B - C * b;
    float Dy = a * C - A * c;

    if (D != 0) {
        cout << "He co 1 nghiem duy nhat:" << endl;
        cout << "x = " << Dx / D << endl;
        cout << "y = " << Dy / D << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He vo so nghiem (VSN)" << endl;
        } else {
            cout << "He vo nghiem (VN)" << endl;
        }
    }

    return 0;
}