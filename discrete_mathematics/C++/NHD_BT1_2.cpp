#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool p, q;

    // --- Bài t?p 1 ---
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    // M?nh d? (a): x + 1 = 2
    p = (x + 1 == 2);

    // M?nh d? (b): x + y = z
    q = (x + y == z);

    cout << "\nKet qua BT1:\n";
    cout << "(a) x + 1 = 2: " << (p ? "Dung" : "Sai") << endl;
    cout << "(b) x + y = z: " << (q ? "Dung" : "Sai") << endl;

    // --- Bài t?p 2 ---
    cout << "\nKet qua BT2:\n";
    cout << "p AND q: " << (p && q) << endl;
    cout << "p OR q : " << (p || q) << endl;
    cout << "NOT p  : " << (!p) << endl;
    cout << "NOT q  : " << (!q) << endl;
    cout << "p XOR q: " << (p ^ q) << endl;  // XOR trong C++

    return 0;
}
