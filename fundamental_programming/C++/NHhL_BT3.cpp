#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << " Nhập cạnh a: ";
    cin >> a;
    cout << " Nhập cạnh b: ";
    cin >> b;
    cout << " Nhập cạnh c: ";
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << '\n';
    }
    else {
        if (a == b && b == c) {
            cout << "HLP" << '\n';
        }
        else {
            cout << "HHCN" << '\n';

            double Sxq = 2 * (a + b) * c;
            cout << " Diện tích xung quanh = " << Sxq << '\n';

            double Sxp = 2 * (a*b + b*c + c*a);
            cout << " Diện tích toàn phần = " << Sxp << '\n';

            double DuongCheo = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
            cout << " Đường Chéo = " << DuongCheo << '\n';

            double TheTich = (double)a * b * c;
            cout << "Thể Tích = " << TheTich << '\n';
        }
    }
}