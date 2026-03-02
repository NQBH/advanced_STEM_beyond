#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const float x = 2.5;
    const float  y = 4.5;
    const float goc = 1.5; // radian
    int a = -15;
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
    cout << "fabs(-2.0) = " << fabs(-2.0) << endl;

    // Ham luong giac
    cout << "cos(" << goc << ") = " << cos(goc) << endl;
    cout << "sin(" << goc << ") = " << sin(goc) << endl;
    cout << "tan(" << goc << ") = " << tan(goc) << endl;

    // Ham luong giac nguoc
    cout << "acos(1.5) = " << acos(1.5) << endl;
    cout << "asin(1.5) = " << asin(1.5) << endl;
    cout << "atan(2.3) = " << atan(2.3) << endl;
    
    // Lam tron
    cout << "floor(4.3) = " << floor(4.3) << endl;
    cout << "ceil(2.5) = " << ceil(2.5) << endl;

return 0;
}
