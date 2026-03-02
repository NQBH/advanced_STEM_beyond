#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "nhap: " << endl;
    cin >> x >> y;
    cout << "tra ve: " << '\n' << endl;
//sqrt
    cout << "sqrt: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << sqrt(x) << endl;
//pow
    cout << "pow: ";
    cout << pow(x, y) << endl;
//exp
    cout << "exp: ";
    cout << exp(x) << endl;
//log
    cout << "log: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << log(x) << endl;
//log10
    cout << "log10: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << log10(x) << endl;
//abs
    cout << "abs: ";
    cout << abs(x) << endl;
//labs
    cout << "labs: ";
    cout << labs(x) << endl;
//fabs
    cout << "fabs: ";
    cout << fabs(x) << endl;
//-----radian-----
//cos
    cout << "cos: ";
    double rad = x * M_PI / 180; // 180 do
    cout << cos(rad) << endl;
//sin
    cout << "sin: ";
    cout << sin(rad) << endl;
//tan
    cout << "tan: ";
    cout << tan(rad) << endl;
//acos
    cout << "acos: ";
    if (rad > 1 || rad < -1) {
        cout << "khong tinh duoc" << endl;
    } else cout << acos(rad) << endl;
//asin
    cout << "asin: ";
    if (rad > 1 || rad < -1) {
        cout << "khong tinh duoc" << endl;
    } else cout << asin(rad) << endl;
//atan
    cout << "atan: ";
    cout << atan(rad) << endl;
//----------------
//floor
    cout << "floor: ";
    cout << floor(x) << endl;
//ceil
    cout << "ceil: ";
    cout << ceil(x) << endl;

}