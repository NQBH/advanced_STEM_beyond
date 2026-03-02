#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main ()
{
    cout << fixed << setprecision(2);
    double a = 9.0, b = 2.0;
    // 1. Lũy thừa và Căn bậc
    cout << "Can bac hai cua " << a << " la: " << sqrt(a) << endl;
    cout << a << " luy thua " << b << " la: " << pow(a, b) << endl;
    cout << "e luy thua " << b << " la: " << exp(b) << endl;
    // 2. Logarit
    cout << "Logarit tu nhien (ln) cua " << a << " la: " << log(a) << endl;
    cout << "Logarit co so 10 cua " << a << " la: " << log10(a) << endl;
    // 3. Giá trị tuyệt đối
    double c = -5.5;
    int d = -10;
    long l = -123456789L;
    cout << "Tri tuyet doi (int) cua " << d << " la: " << abs(d) << endl;
    cout << "Tri tuyet doi (long) cua " << l << " la: " << labs(l) << endl;
    cout << "Tri tuyet doi (double) cua " << c << " la: " << fabs(c) << endl;
    // 4. Lượng giác
    double rad = 3.14159 / 4; // Tuong duong 45 do
    cout << "sin(" << rad << ") = " << sin(rad) << endl;
    cout << "cos(" << rad << ") = " << cos(rad) << endl;
    cout << "tan(" << rad << ") = " << tan(rad) << endl;
    // 5. Lượng giác ngược
    double val = 0.5;
    cout << "asin(" << val << ") = " << asin(val) << " rad" << endl;
    cout << "acos(" << val << ") = " << acos(val) << " rad" << endl;
    cout << "atan(" << val << ") = " << atan(val) << " rad" << endl;
    // 6. Làm tròn
    double e = 3.7;
    cout << "Lam tron " << e << " la: " << round(e) << endl;
    cout << "Lam tron xuong " << e << " la: " << floor(e) << endl;
    cout << "Lam tron len " << e << " la: " << ceil(e) << endl;
    return 0 ;
}