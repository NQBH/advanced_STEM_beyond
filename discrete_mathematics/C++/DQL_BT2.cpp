#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool p, q;

    // Nhập giá trị cho mệnh đề p
    cout << "Nhap x de kiem tra menh de p (x + 1 == 2): ";
    cin >> x;
    p = (x + 1 == 2);

    // Nhập giá trị cho mệnh đề q
    cout << "Nhap x, y, z de kiem tra menh de q (x + y == z): ";
    cin >> x >> y >> z;
    q = (x + y == z);

    // Xuất kết quả các phép logic
    cout << "\nKet qua cac phep toan logic:\n";
    cout << "p AND q: " << (p && q) << endl;
    cout << "p OR q: " << (p || q) << endl;
    cout << "NOT p: " << (!p) << endl;
    cout << "NOT q: " << (!q) << endl;
    cout << "p XOR q: " << (p != q) << endl;

    return 0;
}
