#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;
    cout << "Nhap cac phan tu cua ma tran 2x2 (a b c d): ";
    cin >> a >> b >> c >> d;

    double det = a * d - b * c;

    cout << "Ma tran A: " << endl;
    cout << a << "\t" << b << endl;
    cout << c << "\t" << d << endl;

    cout << "Dinh thuc (det A) = " << det << endl;
    return 0;
}
