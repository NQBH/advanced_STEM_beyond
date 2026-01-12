#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y; cin >> x >> y;
    // can bac hai
    if (x >= 0) cout << sqrt(x) << endl;
    else cout << "khong the tinh can bac hai cua x" << endl;

    // luy thua
    cout << pow(x, y) << endl;

    // e^x
    cout << exp(x) << endl;

    // logarit co so e cua x
    cout << log(x) << endl;

    // logarit co so 10 cua x
    cout << log10(x) << endl;

    // tinh gia tri tuyet doi cua x
    int a; cin >> a;
    long b; cin >> b;
    cout << abs(a) << endl;
    cout << labs(b) << endl;
    cout << fabs(x) << endl;

    // luong giac
    cout << cos(x) << endl;
    cout << sin(x) << endl;
    cout << tan(x) << endl;

    // luong giac nguoc
    cout << acos(x) << endl;
    cout << asin(x) << endl;
    cout << atan(x) << endl;

    // lam tron
    cout << floor(x) << endl;
    cout << ceil(x) << endl;
}