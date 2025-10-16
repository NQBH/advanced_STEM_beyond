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

    
    cout << "Menh de goc (p -> q): " << (!p || q) << '\n';

    cout << "Menh de dao (q -> p): " << (!q || p) << '\n';

    cout << "Phan dao (¬q -> ¬p): " << (q || !p) << '\n';

    cout << "Nghich dao (¬p -> ¬q): " << (p || !q) << '\n';

  
}
