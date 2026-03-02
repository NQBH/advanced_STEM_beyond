#include<iostream>
using namespace std;
int main () {
    double a, b;
    double x;
    cout << "Nhap he so a:";
    cin >> a;
    cout << "Nhap he so b:";
    cin >> b;
    cout << "Phuong trinh cua toi la: " << a << "x + " << b << " = 0" << endl;
    if (a == 0) {
        if (b == 0)
            cout << "Ket qua:Phuong trinh vo so nghiem:" << endl;
        else
            cout << "Ket qua:Phuong trinh vo nghiem:" << endl;
    }
    else {
        x = -b / a;
        cout << "Ket qua:x = " << x << endl;
    }
    return 0;
}