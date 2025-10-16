#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    bool p, q;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;
    p = (x + 1 == 2);
    q = (x + y == z);

    cout << "\n=== KET QUA BT2 ===\n";
    cout << "p AND q : " << (p && q) << endl;
    cout << "p OR q  : " << (p || q) << endl;
    cout << "NOT p   : " << (!p) << endl;
    cout << "NOT q   : " << (!q) << endl;
    cout << "p XOR q : " << (p != q) << endl;

    return 0;
}