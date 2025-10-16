#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Mệnh đề (a)
    cout << "Nhap gia tri x: ";
    cin >> x;
    if (x + 1 == 2) {
        cout << "Menh de (a) x + 1 = 2: Dung" << endl;
    } else {
        cout << "Menh de (a) x + 1 = 2: Sai" << endl;
    }

    // Mệnh đề (b)
    cout << "Nhap gia tri y: ";
    cin >> y;
    cout << "Nhap gia tri z: ";
    cin >> z;

    if (x + y == z) {
        cout << "Menh de (b) x + y = z: Dung" << endl;
    } else {
        cout << "Menh de (b) x + y = z: Sai" << endl;
    }
    bool p, q;

    // Nhập dữ liệu
    cout << "Nhập x: ";
    cin >> x;
    cout << "Nhập y: ";
    cin >> y;
    cout << "Nhập z: ";
    cin >> z;

    // Xét mệnh đề
    p = (x + 1 == 2);
    q = (x + y == z);

    // Xuất kết quả
    cout << boolalpha; // In true/false thay vì 1/0
    cout << "p = (x + 1 == 2) là " << p << endl;
    cout << "q = (x + y == z) là " << q << endl;
    cout << "p and q       = " << (p && q) << endl;
    cout << "p or q        = " << (p || q) << endl;
    cout << "not p         = " << (!p) << endl;
    cout << "not q         = " << (!q) << endl;
    cout << "p xor q       = " << (p != q) << endl;

    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    cout << "Nhap z: "; cin >> z;

    cout << "\n--- Menh de (a): x + 1 = 2 ---" << endl;
    cout << " dao: " << (( x + 1 == 2) && (x == 1)) << endl;
    cout << " phan dao: " << (( x + 1 != 2) && (x != 1)) << endl;
    cout << " nghich dao: " << (( x != 1) && (x + 1 != 2)) << endl;

    cout << "\n--- Menh de (a): x + y = z ---" << endl;
    cout << " dao: " << (( x + y == z) && (z == x + y)) << endl;
    cout << " phan dao: " << (( x + y != z) && (z != x + y)) << endl;
    cout << " nghich dao: " << (( z != x + y) && (x + y != z)) << endl;
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;

    // Kiểm tra bất đẳng thức
    if (  n >= 100) {
        cout << "Dung" << endl;
    } else {
        cout << "Sai" << endl;
    }

    return 0;
}