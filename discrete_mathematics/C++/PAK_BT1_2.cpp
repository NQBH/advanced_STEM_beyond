#include <iostream>
using namespace std;

int main()
{
    bool p, q;  // p: proposition a, q : proposition b
    int x, y, z;
    cout << "Nhap gia tri cua x (so nguyen):" ;
    cin >> x;
    cout << "Nhap gia tri cua y (so nguyen):" ;
    cin >> y;
    cout << "Nhap gia tri cua z (so nguyen):" ;
    cin >> z;
    if (x + 1 == 2)
        p = true;
    else
        p = false;
    if (x + y == z)
        q = true;
    else
        q = false;
    cout << "p and q " << (p && q) << '\n';
    cout << "p or q " << (p || q) << '\n';
    cout << "negative p " << (!p) << '\n';
    cout << "negative q " << (!q) << '\n';
    cout << "p xor q " << (p ^ q) << '\n';
}