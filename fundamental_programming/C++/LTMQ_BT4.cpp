#include <bits/stdc++.h>
using namespace std;

int main() {

    double x, y , b ;

    int a;
    cout << "Nhap x= ";
    cin >> x;
    if (x < 0)
        cout << "Khong co can bac 2";
    else
        cout << "sqrt x = " << sqrt(x) << endl;
    cout << "Nhap x : ";
    cin >> x;
    cout << "Nhap y : ";
    cin >> y;
    cout << "pow x^y = " << pow(x, y) << endl;
    cout << "Nhap x exp: ";
    cin >> x;
    cout << "exp x = " << exp(x) << endl;
    cout << "Nhap x log: ";
    cin >> x;
    if (x <= 0)
        cout << "log x vo nghiem";
    else
        cout << "log x = " << log(x) << endl;
    cout << "Nhap x: ";
    cin >> x;
    if (x <= 0)
        cout << "log10 x vo nghiem";
    else
        cout << "log10x = " << log10(x) << endl;
    cout << "Nhap a : ";
    cin >> a;
    cout << "abs a = " << abs(a) << endl;
    cout << "Nhapb: ";
    cin >> b;
    cout << "labs b = " << labs(b) << endl;
    cout << "Nhap x: ";
    cin >> x;
    cout << "fabs x = " << fabs(x) << endl;
    cout << "Nhap goc x : ";
    cin >> x;
    cout << "sin(x) = " << sin(x) << endl;
    cout << "cos(x) = " << cos(x) << endl;
    cout << "tan(x) = " << tan(x) << endl;
    cout << "Nhap x (-1 <= x <= 1): ";
    cin >> x;
    if (x < -1 || x > 1)
        cout << "asin, scos vo nghiem";
    else {
        cout << "asin x = " << asin(x) << endl;
        cout << "acos x = " << acos(x) << endl;
    }
    cout << "Nhap x : ";
    cin >> x;
    cout << "atan x = " << atan(x) << endl;
    cout << "Nhap x : ";
    cin >> x;
    cout << "floor x = " << floor(x) << endl;
    cout << "Nhap x : ";
    cin >> x;
    cout << "ceil x = " << ceil(x) << endl;
    return 0;
}