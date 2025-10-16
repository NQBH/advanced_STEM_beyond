#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter z: ";
    cin >> z;

    bool p = (x + 1 == 2);
    bool q = (x + y == z);

    cout << "\nProposition p (x + 1 == 2): " << (p ? "True" : "False") << "\n";
    cout << "Proposition q (x + y == z): " << (q ? "True" : "False") << "\n";

    cout << "\nLogical operations between p and q:\n";
    cout << "p AND q: " << ((p && q) ? "True" : "False") << "\n";
    cout << "p OR q: " << ((p || q) ? "True" : "False") << "\n";
    cout << "NOT p: " << ((!p) ? "True" : "False") << "\n";
    cout << "NOT q: " << ((!q) ? "True" : "False") << "\n";
    cout << "p XOR q: " << ((p != q) ? "True" : "False") << "\n";

    return 0;
}