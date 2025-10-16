#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool p, q;

    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;

    // BT1
    p = (x + 1 == 2);
    q = (x + y == z);

    cout << "\n=== BT1 ===\n";
    cout << "(a) x+1=2 : " << (p ? "Dung" : "Sai") << endl;
    cout << "(b) x+y=z : " << (q ? "Dung" : "Sai") << endl;

    // BT2
    cout << "\n=== BT2 ===\n";
    cout << "p AND q : " << (p && q) << endl;
    cout << "p OR q  : " << (p || q) << endl;
    cout << "NOT p   : " << (!p) << endl;
    cout << "NOT q   : " << (!q) << endl;
    cout << "p XOR q : " << (p ^ q) << endl;

    // BT3
    cout << "\n=== BT3 ===\n";
    cout << "(a) Dao=" << (p ? "Dung" : "Sai")
         << ", Phan dao=" << ((!p) ? "Dung" : "Sai")
         << ", Nghich dao=" << ((!p) ? "Dung" : "Sai") << endl;

    cout << "(b) Dao=" << (q ? "Dung" : "Sai")
         << ", Phan dao=" << ((!q) ? "Dung" : "Sai")
         << ", Nghich dao=" << ((!q) ? "Dung" : "Sai") << endl;

    return 0;
}
