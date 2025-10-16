#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool p, q;

    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;

    // Bài 1
    p = (x + 1 == 2);
    q = (x + y == z);

    cout << "\n=== Bai 1 ===\n";
    cout << "(a) x+1=2 : " << (p ? "Dung" : "Sai") << endl;
    cout << "(b) x+y=z : " << (q ? "Dung" : "Sai") << endl;

    // Bài 2
    cout << "\n=== Bai 2 ===\n";
    cout << "p AND q : " << (p && q) << endl;
    cout << "p OR q  : " << (p || q) << endl;
    cout << "NOT p   : " << (!p) << endl;
    cout << "NOT q   : " << (!q) << endl;
    cout << "p XOR q : " << (p ^ q) << endl;

    // Bài 3
    cout << "\n=== Bai 3 (voi p => q) ===\n";
    bool menhde    = (!p || q);     // p => q
    bool dao       = (!q || p);     // q => p
    bool phandao   = (!p || !q);    // ~p => ~q
    bool nghichdao = (!q || !p);    // ~q => ~p

    cout << "p => q             = " << menhde << endl;
    cout << "Dao (q => p)       = " << dao << endl;
    cout << "Phan dao (~p => ~q)= " << phandao << endl;
    cout << "Nghich dao (~q=>~p)= " << nghichdao << endl;

    return 0;
}

