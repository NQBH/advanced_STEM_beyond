#include <iostream>
using namespace std;

int main() {
    double x, y, z;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;
    bool p = (x + 1 == 2);
    bool q = (x + y == z);
    cout << " (a) x + 1 = 2 la " << (p ? "Dung" : "Sai") ;
    cout << " (b) x + y = z la " << (q ? "Dung" : "Sai") ;
    return 0;
}
