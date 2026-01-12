#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Không phải hình hộp chữ nhật
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
        return 0;
    }

    // Hình lập phương
    if (a == b && b == c) {
        cout << "HLP";
        return 0;
    }

    // Hình hộp chữ nhật
    cout << "HHCN" << endl;

    int Sxq = 2 * c * (a + b);
    int Stp = 2 * (a * b + b * c + a * c);
    double d = sqrt(a * a + b * b + c * c);
    int V = a * b * c;

    cout << "Sxq = " << Sxq << endl;
    cout << "Stp = " << Stp << endl;
    cout << "Duong cheo = " << d << endl;
    cout << "The tich = " << V;

    return 0;
}
