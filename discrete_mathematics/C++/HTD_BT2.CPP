#include <iostream>
using namespace std;

int main() {
    double x, y, z;
    bool P, Q;

    // Nhập dữ liệu
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap gia tri y: ";
    cin >> y;
    cout << "Nhap gia tri z: ";
    cin >> z;

    // Mệnh đề
    P = (x + 1 == 2);
    Q = (x + y == z);

    // In kết quả
    cout << "P AND Q: " << (P && Q) << endl;
    cout << "P OR Q: " << (P || Q) << endl;
    cout << "NOT P: " << (!P) << endl;
    cout << "NOT Q: " << (!Q) << endl;
    cout << "P XOR Q: " << (P != Q) << endl; // XOR: true nếu khác nhau
    return 0;
}

