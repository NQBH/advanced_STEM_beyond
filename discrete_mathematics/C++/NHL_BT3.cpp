/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhập x: ";
    cin >> x;
    cout << "Nhập y: ";
    cin >> y;
    cout << "Nhập z: ";
    cin >> z;

    // Mệnh đề P: x + 1 == 2
    bool P = (x + 1 == 2);
    // Mệnh đề Q: x + y == z
    bool Q = (x + y == z);

    // In kết quả của P và Q
    cout << "P: " << (P ? "Đúng" : "Sai") << endl;
    cout << "Q: " << (Q ? "Đúng" : "Sai") << endl;

    // P => Q
    cout << "P => Q: " << ((!P || Q) ? "Đúng" : "Sai") << endl;

    // Đảo: Q => P
    cout << "Q => P (Đảo): " << ((!Q || P) ? "Đúng" : "Sai") << endl;

    // Phản đảo: ~P => ~Q
    cout << "~P => ~Q (Phản đảo): " << ((P || !Q) ? "Đúng" : "Sai") << endl;

    // Nghịch đảo: ~Q => ~P
    cout << "~Q => ~P (Nghịch đảo): " << ((Q || !P) ? "Đúng" : "Sai") << endl;

    return 0;
}