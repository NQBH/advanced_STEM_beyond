#include <iostream>
using namespace std;

int main() {
    double x, y, z;
    bool P, Q;

    // Nhập dữ liệu
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    // Mệnh đề
    P = (x + 1 == 2);
    Q = (x + y == z);

    // Các mệnh đề logic
    bool menh_de_goc = (!P) || Q;       // P → Q
    bool dao = (!Q) || P;               // Q → P
    bool phan_dao = P || (!Q);          // ¬P → ¬Q
    bool phu_dinh_dao = Q || (!P);      // ¬Q → ¬P

    // In kết quả
    cout << "P (x + 1 == 2): " << P << endl;
    cout << "Q (x + y == z): " << Q << endl;
    cout << "P → Q (Menh de goc): " << menh_de_goc << endl;
    cout << "Q → P (Dao): " << dao << endl;
    cout << "¬P → ¬Q (Phan dao): " << phan_dao << endl;
    cout << "¬Q → ¬P (Phu dinh dao): " << phu_dinh_dao << endl;

    return 0;
}

