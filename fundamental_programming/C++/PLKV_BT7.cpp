#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    double vmax, vmin;

    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c = ";
    cin >> c;
    //tìm max
    if (a >= b && a >= c)
        vmax = a;
    else if (b >= a && b >= c)
        vmax = b;
    else
        vmax = c;

    cout << "Max trong 3 so thuc cho truoc = " << vmax << endl;

    // Tim min
    if (a <= b && a <= c)
        vmin = a;
    else if (b <= a && b <= c)
        vmin = b;
    else
        vmin = c;

    cout << "Min trong 3 so thuc cho truoc = " << vmin << endl;

    return 1;
}

