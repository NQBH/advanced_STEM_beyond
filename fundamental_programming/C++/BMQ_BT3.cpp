#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Nhap 3 so nguyen a, b, c: ";
    cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0) {

        if (a == b && b == c) {
            cout << "HLP";
        }
        else {
            cout << "HHCN" << endl;
            cout << "Dien tich xung quanh = " << 2 * c * (a + b) << endl;
            cout << "Dien tich toan phan = " << 2 * (a * b + b * c + a * c) << endl;
            cout << "Duong cheo = " << sqrt(a * a + b * b + c * c) << endl;
            cout << "The tich = " << a * b * c;
        }

    } else {
        cout << -1;
    }

    return 0;
}
