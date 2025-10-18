/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap x; ";
    cin >> x;
    cout << "Nhap y; ";
    cin >> y;
    cout << "Nhap z; ";
    cin >> z;
    bool p = (x + 1 == 2);
    bool q = (x + y == z);
    cout << "\nMệnh đề p (x + 1 == 2): " << (p ? "Đúng" : "Sai") << endl;
    cout << "Mệnh đề q (x + y == z): " << (q ? "Đúng" : "Sai") << endl;
    cout << "\nKết quả các phép logic giữa p và q:" << endl;
    cout << "p AND q: " << ((p && q) ? "Đúng" : "Sai") << endl;
    cout << "p OR q: " << ((p || q) ? "Đúng" : "Sai") << endl;
    cout << "NOT p: " << ((!p) ? "Đúng" : "Sai") << endl;
    cout << "NOT q: " << ((!q) ? "Đúng" : "Sai") << endl;
    cout << "p XOR q: " << ((p != q) ? "Đúng" : "Sai") << endl;
    
    
    return 0;
}