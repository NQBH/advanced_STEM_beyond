#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    cout << "nhap x,y:" << x << "," << y << endl;
    cout << "cac ham trang 2.15: \n";

    // Can bac hai
    if (x >= 0)
        cout << "sqrt(x) = " << sqrt(x) << endl;
    else
        cout << "sqrt(x): Khong tinh duoc (x < 0)\n";

    // Luy thua
    if (x > 0)
        cout << "pow(x, y) = " << pow(x, y) << endl;
    else
        cout << "pow(x, y): Khong tinh duoc (x <= 0)\n";

    // Ham mu va logarit
    cout << "exp(x) = " << exp(x) << endl;

    if (x > 0) {
        cout << "log(x) = " << log(x) << endl;
        cout << "log10(x) = " << log10(x) << endl;
    } else {
        cout << "log(x), log10(x): Khong tinh duoc (x <= 0)\n";
    }

    // Tri tuyet doi
    cout << "abs((int)x) = " << abs((int)x) << endl;
    cout << "fabs(x) = " << fabs(x) << endl;

    // Ham luong giac radian
    cout << "sin(x) = " << sin(x) << endl;
    cout << "cos(x) = " << cos(x) << endl;
    cout << "tan(x) = " << tan(x) << endl;

    // Ham luong giac nguoc
    if (x >= -1 && x <= 1) {
        cout << "asin(x) = " << asin(x) << endl;
        cout << "acos(x) = " << acos(x) << endl;
    } else {
        cout << "asin(x), acos(x): Khong tinh duoc (|x| > 1)\n";
    }

    cout << "atan(x) = " << atan(x) << endl;

    // so nguyen lon
    cout << "floor(x) = " << floor(x) << endl;
    cout << "ceil(x) = " << ceil(x) << endl;

    return 0;
}
