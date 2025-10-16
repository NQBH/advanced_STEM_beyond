#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhập x: ";
    cin >> x;
    cout << "Nhập y: ";
    cin >> y;
    cout << "Nhập z: ";
    cin >> z;

    // Mệnh đề
    bool p = (x + 1 == 2);       // Menh de a
    bool q = (x + y == z);       // Menh de b

    cout << "\n--- Kết quả mệnh đề ---" << endl;
    cout << "Mệnh đề (a): x + 1 = 2 là " << (p ? "Đúng" : "Sai") << endl;
    cout << "Mệnh đề (b): x + y = z là " << (q ? "Đúng" : "Sai") << endl;

    // Các phép
    cout << "\n--- Các phép logic ---" << endl;
    cout << "p & q: " << (p && q ? "true" : "false") << endl;
    cout << "p or q: " << (p || q ? "true" : "false") << endl;
    cout << "Not p: " << (!p ? "true" : "false") << endl;
    cout << "Not q: " << (!q ? "true" : "false") << endl;
    cout << "p xor q: " << ((p ^ q) ? "true" : "false") << endl;

    // Mệnh đề đảo, phản đảo, nghịch đảo
    cout << "\n--- Mệnh đề suy diễn ---" << endl;
    cout << "Đảo (¬p): " << (!p ? "true" : "false") << endl;
    cout << "Phản đảo (¬q → ¬p): " << ((!q) <= (!p) ? "true" : "false") << endl;
    cout << "Nghịch đảo (q → p): " << (q <= p ? "true" : "false") << endl;

    // mệnh đề 2^n
    double n;
    cin >> n;
    if (pow(2, n) >= 100) cout << "true" << '\n';
    else cout << "false";
    return 0;
}