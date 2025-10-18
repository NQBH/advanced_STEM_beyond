#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    bool P, Q;
    
    // Nhập dữ liệu
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    cout << "Nhap z: "; cin >> z;

    // Xác định mệnh đề
    P = (x + 1 == 2);
    Q = (x + y == z);

    cout << "\nMenh de ban dau:\n";
    cout << "P (x + 1 == 2): " << P << endl;
    cout << "Q (x + y == z): " << Q << endl;

    // 1. Đảo: Q ⇒ P
    bool converse = (!Q) || P;

    // 2. Nghịch đảo: ¬P ⇒ ¬Q
    bool inverse = (!P) || (!Q);

    // 3. Phản đảo: ¬Q ⇒ ¬P
    bool contrapositive = (!Q) || (!P);

    // In kết quả
    cout << "\nKet qua:\n";
    cout << "Dao (Q => P): " << converse << endl;
    cout << "Nghich dao (¬P => ¬Q): " << inverse << endl;
    cout << "Phan dao (¬Q => ¬P): " << contrapositive << endl;

    return 0;
}
