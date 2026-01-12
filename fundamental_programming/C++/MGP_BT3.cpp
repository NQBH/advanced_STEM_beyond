#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Hình lập phương
    if (a > 0 && a == b && b == c) {
        cout << "HLP";
    }
    // Hình hộp chữ nhật
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;

        float Sxq = 2 * (a + b) * c;           // Diện tích xung quanh
        float Stp = 2 * (a*b + b*c + a*c);     // Diện tích toàn phần
        float d = sqrt(a*a + b*b + c*c);    // Đường chéo
        float V = a * b * c;                   // Thể tích

        cout << "Dien tich xung quanh: " << Sxq << endl;
        cout << "Dien tich toan phan: " << Stp << endl;
        cout << "Duong cheo: " << d << endl;
        cout << "The tich: " << V;
    }
    // Không phải hình hộp chữ nhật
    else {
        cout << -1;
    }

    return 0;
}
