#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    double vmax, vmin;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    if (a >= b && a >= c)
        vmax = a;
    else if (b >= a && b >= c)
        vmax = b;
    else
        vmax = c;
    if (a <= b && a <= c)
        vmin = a;
    else if (b <= a && b <= c)
        vmin = b;
    else
        vmin = c;
    cout << "So lon nhat (vmax): " << vmax << endl;
    cout << "So nho nhat (vmin): " << vmin << endl;
    return 0;
}
