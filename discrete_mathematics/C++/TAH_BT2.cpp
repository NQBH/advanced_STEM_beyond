#include<iostream>

using namespace std;

int main()
{
    int x, y, z;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    // (a) Kiểm tra mệnh đề x + 1 = 2
    if (x + 1 == 2)
        cout << "(a) Dung" << endl;
    else
        cout << "(a) Sai" << endl;

    // (b) Kiểm tra mệnh đề x + y = z
    if (x + y == z)
        cout << "(b) Dung" << endl;
    else
    cout << "(b) Sai" << endl;
     // Mệnh đề từ BT1
    bool p = (x + 1 == 2);
    bool q = (x + y == z);

    // Xuất kết quả
    cout << "p = " << (p ? "Dung" : "Sai") << endl;
    cout << "q = " << (q ? "Dung" : "Sai") << endl;
    cout << "p and q = " << ((p && q) ? "Dung" : "Sai") << endl;
    cout << "p or q = " << ((p || q) ? "Dung" : "Sai") << endl;
    cout << "not p = " << ((!p) ? "Dung" : "Sai") << endl;
    cout << "not q = " << ((!q) ? "Dung" : "Sai") << endl;
    cout << "p xor q = " << ((p ^ q) ? "Dung" : "Sai") << endl;

    return 0;
}
