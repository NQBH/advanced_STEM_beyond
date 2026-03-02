#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;

    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;

    // sqrt
    if (x < 0)
        cout << "sqrt(x): x must be nonnegative\n";
    else
        cout << "sqrt(x) = " << sqrt(x) << endl;

    // pow
    cout << "pow(x, y) = " << pow(x, y) << endl;

    // exp
    cout << "exp(x) = " << exp(x) << endl;

    // log
    if (x <= 0)
        cout << "log(x): x must be positive\n";
    else
        cout << "log(x) = " << log(x) << endl;

    // log10
    if (x <= 0)
        cout << "log10(x): x must be positive\n";
    else
        cout << "log10(x) = " << log10(x) << endl;

    // abs, labs, fabs
    cout << "abs((int)x) = " << abs((int)x) << endl;
    cout << "labs((long)x) = " << labs((long)x) << endl;
    cout << "fabs(x) = " << fabs(x) << endl;

    // cac ham luong giac (radian)
    cout << "cos(x) = " << cos(x) << endl;
    cout << "sin(x) = " << sin(x) << endl;
    cout << "tan(x) = " << tan(x) << endl;

    // cac ham luong giac nguoc
    if (x >= -1 && x <= 1) {
        cout << "acos(x) = " << acos(x) << endl;
        cout << "asin(x) = " << asin(x) << endl;
    } else {
        cout << "acos(x), asin(x): x must be in [-1, 1]\n";
    }

    cout << "atan(x) = " << atan(x) << endl;

    // floor va ceil
    cout << "floor(x) = " << floor(x) << endl;
    cout << "ceil(x) = " << ceil(x) << endl;

    return 0;
}