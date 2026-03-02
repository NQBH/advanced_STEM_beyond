#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    int a;
    long b;
    float c;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    if ( x >= 0 )
        cout << "Can bac hai cua x la: " << sqrt(x) << endl;
    else
        cout << "Can bac hai khong the tinh duoc (x < 0)" << endl;

    cout << "Luy thua cua x mu y la: " << pow(x, y) << endl;

    cout << "e mu x la: " << exp(x) << endl;

    if ( x > 0 ) {
        cout << "Logarit co so e cua x la: " << log(x) << endl;
        cout << "Logarit co so 10 cua x la " << log10(x) << endl;
    } else {
        cout << "Logarit khong tinh duoc (x <= 0)" << endl;
    }

    cout << "So nguyen a: " << abs(a) << endl;
    cout << "So nguyen dai b: " << labs(b) << endl;
    cout << "So thuc c: " << fabs(c) << endl;

    cout << " Cos(x) = " << cos(x) << endl;
    cout << " Sin(x) = " << sin(x) << endl;
    cout << " Tg(x) = " << tan(x) << endl;

    if ( x >= -1 && x <= 1 ) {
        cout << " Arccos(x) = " << acos(x) << endl;
        cout << " Arcsin(x) = " << asin(x) << endl;
    } else {
        cout << "Gia tri khong hop le de tinh ham luong giac nguoc" << endl;
    }
    cout << " Arctg(x) = " << atan(x) << endl;

    cout << "So nguyen lon nhat khong vuot qua x: " << floor(x) << endl;
    cout << "So nguyen nho nhat lon hon hoac bang x: " << ceil(x) << endl; \
    return 0;
}