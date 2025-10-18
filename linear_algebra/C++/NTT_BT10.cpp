#include <iostream>
using namespace std;

int main() {
     double a, b, c, d;
     cout << " Chuong trinh dinh thuc ma tran 2x2" << endl;
     cout << " | a  b |" << endl;
     cout << " | c  d |" << endl;
     cout << " Nhap a, b, c, d: ";
     cin >> a >> b >> c >> d;

     double determinant = a * d - b * c;
     cout << " Dinh thuc = " << determinant << endl;
     return 0;
}