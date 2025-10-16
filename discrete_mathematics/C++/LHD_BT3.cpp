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
    if (x + 1 == 2) // normal one
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if ((x + 1 == 2) == true) // reverse one
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if (x + 1 != 2) // inverse one
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if ((x + 1 == 2) == false) // opposite one
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if (x + y == z) // normal one
        cout << "q true" << endl;
    else
        cout << "q false" << endl;
    if ((x + y == z) == true) // reverse one
        cout << "q true" << endl;
    else
        cout << "q false" << endl;
    if (x + y != z) // inverse one
        cout << "q true" << endl;
    else
        cout << "q false" << endl;
    if ((x + y == z) == false) // opposite one
        cout << "q true" << endl;
    else
        cout << "q false" << endl;
    return 0;
}