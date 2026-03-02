#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout<< "nhap x: ";
    cin>>x;
    cout<< "nhap y: ";
    cin>>y;

    // sqrt
    if (x < 0)
        cout << "sqrt(x): x must be nonnegative\n";
    else
        cout << "sqrt(x) = " << sqrt(x) << endl;

    // pow 
        cout << "pow(x, y)= " << pow(x, y) << endl;

    // exp
        cout << "exp(x)= " << exp(x)    << endl;

    // log
        cout << "log(x)= " <<log(x)    << endl;

    // log10
    cout << "log10(x)= " <<log10(x) << endl;

    // fabs
    cout << "fabs(x)= " <<fabs(x) << endl;

    // cos, sin, tan 
    cout << "cos(x)= " << cos(x) << endl;
    cout << "sin(x)= " << sin(x) << endl;
    cout << "tan(x)= " << tan(x) << endl;

    // acos, asin
    if (x < -1 || x > 1)
        cout << "acos(x): x must be in [-1,1]\n";
    else
        cout << "acos(x) = " << acos(x) << endl;

    if (x < -1 || x > 1)
        cout << "asin(x): x must be in [-1,1]\n";
    else
        cout << "asin(x) = " << asin(x) << endl;

    // atan
    cout << "atan(x) = " << atan(x) << endl;

    // floor, ceil
    cout << "floor(x) = " << floor(x) << endl;
    cout << "ceil(x) = " << ceil(x) << endl;

    // abs, labs
    int a;
    long b;

    cout << "Nhap a (int): ";
    cin >> a;
    cout << "abs(a) = " << abs(a) << endl;

    cout << "Nhap b (long): ";
    cin >> b;
    cout << "labs(b) = " << labs(b) << endl;

    return 0;
}