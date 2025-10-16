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
    bool p = (x + 1 == 2);
    bool q = (x + y == z);
    cout << "a" << (p ? "true" : "false") << endl;
    cout << "b" << ((p ^ q) ? "true" : "false") << endl;
    if (p && q)
        cout << "p and q are both true" << endl;
    else
        cout << "p and q are not both true" << endl;
    if (p || q)
        cout << "p or q is true" << endl;
    else
        cout << "p or q is not true" << endl;
    if (!p && !q)
        cout << "p and q are both true and return false" << endl;
    else
        cout << "p and q are not both true and return true" << endl;
    return 0;
}