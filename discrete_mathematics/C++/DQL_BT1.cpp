#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // (a) Kiểm tra mệnh đề x + 1 = 2
    cout << "(a) Nhap gia tri x: ";
    cin >> x;

    if (x + 1 == 2) {
        cout << "Menh de (a) dung." << endl;
    } else {
        cout << "Menh de (a) sai." << endl;
    }

    // (b) Kiểm tra mệnh đề x + y = z
    cout << "(b) Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap gia tri y: ";
    cin >> y;
    cout << "Nhap gia tri z: ";
    cin >> z;

    if (x + y == z) {
        cout << "Menh de (b) dung." << endl;
    } else {
        cout << "Menh de (b) sai." << endl;
    }

    return 0;
}
