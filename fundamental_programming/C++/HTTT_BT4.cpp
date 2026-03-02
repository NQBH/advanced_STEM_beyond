#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 9.0;
    double y = 4.0;
    double goc = 1.0; // radian
    int a = -16;

    cout << "Cac ham toan hoc trong thu vien chuan cua C/C++:" << endl;

    // Can bac hai
    cout << "sqrt(" << x << ") = " << sqrt(x) << endl;

    // Luy thua
    cout << "pow(" << x << ", " << y << ") = " << pow(x, y) << endl;

    // Ham mu e^x
    cout << "exp(" << y << ") = " << exp(y) << endl;

    // Logarit tu nhien
    cout << "log(" << x << ") = " << log(x) << endl;

    // Logarit co so 10
    cout << "log10(" << x << ") = " << log10(x) << endl;

    // Gia tri tuyet doi
    cout << "abs(" << a << ") = " << abs(a) << endl;
    cout << "fabs(-2.3) = " << fabs(-2.3) << endl;

    // Ham luong giac
    cout << "cos(" << goc << ") = " << cos(goc) << endl;
    cout << "sin(" << goc << ") = " << sin(goc) << endl;
    cout << "tan(" << goc << ") = " << tan(goc) << endl;

    // Ham luong giac nguoc
    cout << "acos(1.0) = " << acos(1.0) << endl;
    cout << "asin(1.0) = " << asin(1.0) << endl;
    cout << "atan(1) = " << atan(1) << endl;

    // Lam tron
    cout << "floor(8,4) = " << floor(8.4) << endl;
    cout << "ceil(8.4) = " << ceil(8.4) << endl;

    return 0;
}