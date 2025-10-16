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

    cout << "\n=== KET QUA BT1 ===\n";
    cout << "(a) x + 1 = 2 la " << (p ? "dung" : "sai") << endl;
    cout << "(b) x + y = z la " << (q ? "dung" : "sai") << endl;

    return 0;
}