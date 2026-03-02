#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    double x, y;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    if (x >= 0)
    cout << "Can bac hai cua x = " << sqrt(x) << '\n';
    else
    cout << "sqrt(x) khong xac dinh" << '\n';

    cout << "x luy thua y=" << pow(x, y) << '\n';
    cout << "e mu x voi e la co so logarit tu nhien=" << exp(x)  << '\n';

    if (x > 0) {
    cout << "log(x) = " << log(x) << '\n';
    cout << "log10(x) = " << log10(x) << '\n';
    } else {
    cout << "log va log10 khong xac dinh" << '\n';
    }
    
    cout << "tri tuyet doi voi int x=" << abs(x) << '\n';
    cout << "tri tuyet doi voi long x=" << labs(x) << '\n';
    cout << "tri tuyet doi voi double x=" << fabs(x) << '\n';
    cout << "cos(x)=" << cos(x) << '\n';
    cout << "sin(x)=" << sin(x) << '\n';
    cout << "tan(x)=" << tan(x) << '\n';
    cout << "acos(x)=" << acos(x) << '\n';
    cout << "asin(x)=" << asin(x) << '\n';
    cout << "atan(x)=" << atan(x) << '\n';
    cout << "floor(x)=" << floor(x) << '\n';
    cout << "ceil(x)=" << ceil(x) << '\n';
    
}