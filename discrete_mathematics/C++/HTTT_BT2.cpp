

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
    
    bool p = (x + 1 == 2);
    bool q = (x + y == z);
    
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    
    cout << "p and q: " << (p && q) << endl;
    cout << "p or q: " << (p || q) << endl;
    cout << "not p: " << (!p) << endl;
    cout << "not q: " << (!q) << endl;
    cout << "p xor q: " << (p ^ q) << endl;
    
    return 0;
}