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

    bool dao = (!q) || p;      // q → p  <=> !q OR p
    bool phan_dao = p || (!q); // ¬p → ¬q <=> p OR !q
    bool nghich_dao = q || (!p); // ¬q → ¬p <=> q OR !p

    cout << "\n=== KET QUA BT3 ===\n";
    cout << "Dao (q -> p)          : " << dao << endl;
    cout << "Phan dao (!p -> !q)   : " << phan_dao << endl;
    cout << "Nghich dao (!q -> !p) : " << nghich_dao << endl;

    return 0;
}