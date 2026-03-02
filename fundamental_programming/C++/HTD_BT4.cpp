#include <iostream>
#include <cmath>    // Thu vien chua cac ham toan hoc
using namespace std;

int main() {

    cout << "CHUONG TRINH THU CAC HAM TOAN HOC (BANG 2.15)\n";

    // 1. Ham tri tuyet doi
    cout << "\n1. HAM TRI TUYET DOI\n";
    int a;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Tri tuyet doi cua a = " << abs(a) << endl;

    // 2. Ham lam tron
    cout << "\n2. HAM LAM TRON\n";
    double x;
    cout << "Nhap so thuc x: ";
    cin >> x;
    cout << "Lam tron len (ceil)  = " << ceil(x) << endl;
    cout << "Lam tron xuong (floor) = " << floor(x) << endl;

    // 3. Ham luy thua va can bac hai
    cout << "\n3. HAM LUY THUA VA CAN BAC HAI\n";
    double m, n;
    cout << "Nhap co so m: ";
    cin >> m;
    cout << "Nhap so mu n: ";
    cin >> n;
    cout << "m mu n = " << pow(m, n) << endl;

    if (m >= 0) {
        cout << "Can bac hai cua m = " << sqrt(m) << endl;
    } else {
        cout << "Khong tinh duoc can bac hai cua so am\n";
    }

    // 4. Ham luong giac
    cout << "\n4. HAM LUONG GIAC\n";
    double goc;
    cout << "Nhap goc (don vi do): ";
    cin >> goc;

    double rad = goc * 3.14159265 / 180;
    cout << "sin(goc) = " << sin(rad) << endl;
    cout << "cos(goc) = " << cos(rad) << endl;
    cout << "tan(goc) = " << tan(rad) << endl;

    // 5. Ham logarit va so e
    cout << "\n5. HAM LOGARIT VA SO E\n";
    double y;
    cout << "Nhap so duong y: ";
    cin >> y;

    if (y > 0) {
        cout << "e mu y = " << exp(y) << endl;
        cout << "ln(y)  = " << log(y) << endl;
        cout << "log10(y) = " << log10(y) << endl;
    } else {
        cout << "Khong tinh duoc log voi so khong duong\n";
    }

    return 0;
}
