#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;

    cout << "Nhap cac phan tu cua ma tran 2x2 (dang a b; c d):" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    cout << "\nma tran A:\n";
    cout << a << "  " << b << endl;
    cout << c << "  " << d << endl;
    double det = a * d - b * c;
    cout << "\ndinh thuc cua ma tran (det A) = " << det << endl;
    return 0;
}