#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool p, q;
    cout << "gia tr x: ";
    cin >> x;

    cout << "gia tri y: ";
    cin >> y;

    cout << "Ngia tri z: ";
    cin >> z;
    if (x + 1 == 2) {
        p = true;
    } else {
        p = false;
    }
    if (x + y == z) {
        q = true;
    } else {
        q = false;
    }
    cout << "(a): x + 1 == 2 " << (p ? "true" : "false") << endl;
    cout << "(b): x + y == z " << (q ? "true" : "false") << endl;

    return 0;
}