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

    // mệnh đề a: x + 1 = 2
    bool p = (x + 1 == 2);

    // mệnh đề b: x + y = z
    bool q = (x + y == z);

    cout << "(a) x + 1 = 2 la: " << (p ? "Dung" : "Sai") << endl;
    cout << "(b) x + y = z la: " << (q ? "Dung" : "Sai") << endl;

    return 0;
}