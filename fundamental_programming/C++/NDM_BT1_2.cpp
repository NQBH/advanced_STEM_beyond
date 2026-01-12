#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // tinh chu vi & dien tich hinh vuong
    float a;
    cout << "Nhap do dai canh hinh vuong: ";
    cin >> a;
    float P = a + a + a + a;
    float S = a * a;
    cout << "Dien tich hinh vuong: " << S << '\n';
    cout << "Chu vi hinh vuong: " << P << '\n';

    // tinh toan hinh chu nhat
    float d, r;
    cout << "Nhap chieu dai hinh chu nhat: ";
    cin >> d;
    cout << "Nhap chieu rong hinh chu nhat: ";
    cin >> r;

    float P2 = 2 * (d + r);
    float S2 = d * r;
    float Duongcheo = sqrt(d * d + r * r);

    cout << "Chu vi hinh chu nhat: " << P2 << '\n';
    cout << "Dien tich hinh chu nhat: " << S2 << '\n';
    cout << "Duong cheo hinh chu nhat: " << Duongcheo << '\n';

    return 0;
}