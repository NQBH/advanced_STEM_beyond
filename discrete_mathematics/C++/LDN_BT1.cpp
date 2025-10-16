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

    if (x + 1 == 2)
        cout << "(a) x + 1 = 2 la DUNG." << '\n';
    else
        cout << "(a) x + 1 = 2 la SAI." << '\n';

    if (x + y == z)
        cout << "(b) x + y = z la DUNG." << '\n';
    else
        cout << "(b) x + y = z la SAI." << '\n';
}