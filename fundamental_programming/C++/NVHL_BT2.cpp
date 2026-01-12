#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float d, r;
    cout << "nhap chieu dai: ";
    cin >> d;
    cout << "nhap chieu rong: ";
    cin >> r;

    float chuvi = (d + r) * 2;
    float dientich = d * r;
    float duongcheo = sqrt(d * d + r * r);
    cout << "chu vi: " << chuvi << endl;
    cout << "dien tich: " << dientich << endl;
    cout << "duong cheo: " << duongcheo << endl;
    return 0;
}
