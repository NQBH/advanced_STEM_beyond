#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "input x: ";
    cin >> x;
    cout << "input y: ";
    cin >> y;
    cout << "input z: ";
    cin >> z;
    if (x + 1 == 2)
        cout << "(a) true" << endl;
    else
        cout << "(a) false" << endl;
    if (x + y == z)
        cout << "(b) true" << endl;
    else
        cout << "(b) false" << endl;
    return 0;
}