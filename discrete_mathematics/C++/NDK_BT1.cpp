#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << " Nhap x: ";
    cin >> x;
    cout << " Nhap y: ";
    cin >> y;
    cout << " Nhap z: ";
    cin >> z;
    // Kiem tra menh de (a)
    if ( x + 1 == 2)
        cout << "(a) Dung" << endl;
    else
        cout << "(a) Sai" << endl;

    // Kiem tra menh de (b)
    if ( x + y == z )
        cout << "(b) Dung" << endl;
    else
        cout << "(b) Sai" << endl;

    return 0;
}