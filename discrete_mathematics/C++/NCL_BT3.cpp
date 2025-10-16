#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    cout << "Nhap z: "; cin >> z;

    // Mệnh đề P và Q
    bool P = (x + 1 == 2);
    bool Q = (x + y == z);

    // Các mệnh đề suy diễn
    bool P_implies_Q = (!P) || Q;       // P => Q
    bool Q_implies_P = (!Q) || P;       // Q => P (đảo)
    bool notQ_implies_notP = (Q == false) ? true : (!P); // !Q => !P (phản đảo)
    bool notP_implies_notQ = (P == false) ? true : (!Q); // !P => !Q (nghịch đảo)

    cout << "P = " << P << endl;
    cout << "Q = " << Q << endl;
    cout << "P => Q = " << P_implies_Q << endl;
    cout << "Dao (Q => P) = " << Q_implies_P << endl;
    cout << "Phan dao (¬Q => ¬P) = " << notQ_implies_notP << endl;
    cout << "Nghich dao (¬P => ¬Q) = " << notP_implies_notQ << endl;

    return 0;
}
