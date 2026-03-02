#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cout << " a nho = " << endl;
    cin >> a;
    cout << " b nho = " << endl;
    cin >> b;
    cout << " c nho =  " << endl;
    cin >> c;
    cout << " A lon = " << endl;
    cin >> A;
    cout << " B  lon = " << endl;
    cin >> B;
    cout << " C lon = " << endl;
    cin >> C;

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (Dx == 0 && Dy == 0) {
        cout << "pt vo so nghnghiem" << endl;
    } else if (Dx != 0 ) {
        cout << "pt co 1 nghiem duy nhat x = " << Dx / D << ", y = " << Dy / D << endl;
    } else {
        cout << "pt vo nghiem " << endl;
    }
    return 0;
}
