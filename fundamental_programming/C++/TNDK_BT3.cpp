#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cout << "nhap 3 so nguyen vao chieu dai rong cao: " << endl;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "loi so";
        return 0;
    }

    if (a == b && b == c) {
        cout << "HLP" << endl;
        return 0;
    } else {
        cout << "HHCN" << endl;
    }

    cout << "dien tich xung quanh: " << 2 * c*(a + b) << endl;
    cout << "dien tich toan phan: " << 2 * (a * b + b * c + c * a) << endl;
    cout << "duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
    cout << "the tich: " << a*b*c << endl;
}