#include <iostream>
using namespace std;

int main()
{
    bool p, q;
    cout << "Nhap p (0 hoac 1): ";
    cin >> p;
    cout << "Nhap q (0 hoac 1): ";
    cin >> q;

    bool dao = (!q) || p;        // q → p
    bool phan_dao = q || (!p);   // ¬p → ¬q
    bool nghich_dao = p || (!q); // ¬q → ¬p

    cout << "Dao (q -> p): " << dao << endl;
    cout << "Phan dao (!p -> !q): " << phan_dao << endl;
    cout << "Nghich dao (!q -> !p): " << nghich_dao << endl;

    return 0;
}
