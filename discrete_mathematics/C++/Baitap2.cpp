#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Nhap giá tri?
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    // Ðinh nghia menh de ?
    bool p = (x + 1 == 2);
    bool q = (x + y == z);

    // Xuat ket qua ?
    cout << "p = " << p << ", q = " << q << '\n';
    cout << "p AND q = " << (p && q) << '\n';
    cout << "p OR q = " << (p || q) << '\n';
    cout << "NOT p = " << (!p) << '\n';
    cout << "NOT q = " << (!q) << '\n';
    cout << "p XOR q = " << (p != q) << '\n';

}
