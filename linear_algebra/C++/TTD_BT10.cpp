#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;

    cout << "Nhap cac phan tu cua ma tran 2x2:\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;

    cout << "\nMa tran A la:\n";
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    double det = a * d - b * c;

    cout << "\nDinh thuc det(A) = a*d - b*c = " << a << "*" << d
         << " - " << b << "*" << c << " = " << det << endl;

    return 0;
}
