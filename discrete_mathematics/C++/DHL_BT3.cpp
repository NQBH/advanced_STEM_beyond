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

    cout << " (a) x + 1 = 2 la " << (p ? "Dung" : "Sai") << endl ;
    cout << " (b) x + y = z la " << (q ? "Dung" : "Sai") << endl ;

    cout << "p and q: " << (p && q) << endl;
    cout << "p or q: " << (p || q) << endl;
    cout << "not p: " << (!p) << endl;
    cout << "not q: " << (!q) << endl;
    cout << "p xor q: " << (p != q) << endl;

    bool converse = (!q || p);
    bool inverse = (!p || !q);
    bool contrapositive = (!q || !p);

    cout << "Dao (q => p): " << converse << endl;
    cout << "Nghich dao (~p => ~q): " << inverse << endl;
    cout << "Phan dao (~q => ~p): " << contrapositive << endl;
    return 0;
}