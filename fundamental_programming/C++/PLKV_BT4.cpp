#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    double x = 16.0;
    double y = 3.0;
    double goc = 1.2;
    int a = -25;

    cout << "Chuong trinh minh hoa ham toan hoc C++" << '\n';

    // Can bac hai
    cout << "sqrt(16) = " << sqrt(16) << '\n';

    // Luy thua
    cout << "pow(x, 2) = " << pow(x, 2) << '\n';

    // Ham mu
    cout << "exp(1) = " << exp(1) << '\n';

    // Logarit
    cout << "log(x) = " << log(x) << '\n';
    cout << "log10(x) = " << log10(x) << '\n';

    // Gia tri tuyet doi
    cout << "abs(a) = " << abs(a) << '\n';
    cout << "fabs(-5.8) = " << fabs(-5.8) << '\n';

    // Ham luong giac
    cout << "sin(goc) = " << sin(goc) << '\n';
    cout << "cos(goc) = " << cos(goc) << '\n';

    // Ham luong giac nguoc
    cout << "atan(0.5) = " << atan(0.5) << '\n';

    // Lam tron
    cout << "floor(6.4) = " << floor(6.4) << '\n';
    cout << "ceil(6.4) = " << ceil(6.4) << '\n';

    return 0;
}