#include <iostream>
using namespace std;
int main() {
    float a, b, c, d;  
    cout << "Nhap cac phan tu cua ma tran 2x2 (a b; c d):\n";
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    cout << "Nhap d: ";
    cin >> d;

    float det = a * d - b * c;

    cout << "\nMa tran A la:\n";
    cout << "| " << a << "  " << b << " |\n";
    cout << "| " << c << "  " << d << " |\n";

    cout << "\nDinh thuc (det A) = a*d - b*c = " << det << endl;

    return 0;
}