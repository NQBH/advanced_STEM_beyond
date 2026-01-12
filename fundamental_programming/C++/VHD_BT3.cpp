#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Kiểm tra điều kiện hợp lệ
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
        return 0;
    }

    // Hình lập phương
    if (a == b && b == c) {
        cout << "HLP";
    }
    // Hình hộp chữ nhật
    else {
        cout << "HHCN" << endl;

        int dienTichXQ = 2 * c * (a + b);
        int dienTichTP = 2 * (a*b + a*c + b*c);
        double duongCheo = sqrt(a*a + b*b + c*c);
        int theTich = a * b * c;

        cout << "Dien tich xung quanh = " << dienTichXQ << endl;
        cout << "Dien tich toan phan = " << dienTichTP << endl;
        cout << "Duong cheo = " << duongCheo << endl;
        cout << "The tich = " << theTich;
    }

    return 0;
}