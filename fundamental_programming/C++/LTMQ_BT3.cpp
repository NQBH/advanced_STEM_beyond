#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c = ";
    cin >> c;
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1; '\n';
        return 0;
    }
    if (a == b && b == c) {
        cout << "HLP";
    }
    else {
        cout << "HHCN" << endl;

        float Sxq, Stp, duongcheo, thetich;
        Sxq = 2 * c * (a + b);
        Stp = 2 * (a * b + a * c + b * c);
        duongcheo = sqrt(a * a + b * b + c * c);
        thetich = a * b * c;

        cout << "dien tich xung quanh = " << Sxq << endl;
        cout << "dien tich toan phan = " << Stp << endl;
        cout << "duong cheo = " << duongcheo << endl;
        cout << "the tich = " << thetich << endl;
    }

    return 0;
}