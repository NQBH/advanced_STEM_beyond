#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    bool p = (x + 1 == 2);
    bool q = (x + y == z);

    cout << "Menh de (a): x + 1 == 2 --> " << (p ? "true" : "false") << endl;
    cout << "Menh de (b): x + y == z --> " << (q ? "true" : "false") << endl;

    // BT2
    cout << "p and q: " << (p && q ? "true" : "false") << endl;
    cout << "p or q: " << (p || q ? "true" : "false") << endl;
    cout << "not p: " << (!p ? "true" : "false") << endl;
    cout << "not q: " << (!q ? "true" : "false") << endl;
    cout << "p xor q: " << ((p != q) ? "true" : "false") << endl;
    cout << "not (p and q): " << (!(p && q) ? "true" : "false") << endl;

    return 0;
}
