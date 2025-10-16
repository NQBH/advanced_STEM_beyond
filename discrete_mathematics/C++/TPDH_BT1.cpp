#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool a, b; // a: Proposition 1, b: Proposition 2
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;
    if (x + 1 == 2) a = true;
    else a = false;
    if (x + y == z) b = true;
    else b = false;
    cout << "Proposition 1 is " << a << endl;
    cout << "Proposition 2 is " << b << endl;
    return 0;
}