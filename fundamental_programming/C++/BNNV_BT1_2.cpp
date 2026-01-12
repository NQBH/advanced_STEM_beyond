#include<iostream>
#include<cmath>
using namespace std;

int main() {
//BT1: nhap canh hv. Tinh CV, DT hv
    double c;

    cout << "Nhap canh hinh vuong c = " << endl;
    cin >> c;

    cout << "Chu vi hinh vuong: " << c * 4 << endl;
    cout << "Dien tich hinh vuong: " << c * c << endl;

//BT2: nhap chieu dai, rong hcn. Tinh CV, DT, Do dai hcn
    double d, r;

    cout << "Nhap gia tri cua chieu dai d = " << endl;
    cin >> d;

    cout << "Nhap gia tri cua chieu rong r = " << endl;
    cin >> r;

    cout << "Chu vi hinh chu nhat: " << (d + r) * 2 << endl;
    cout << "Dien tich hinh chu nhat: " << d * r << endl;
    cout << "Do dai duong cheo hinh chu nhat: " << sqrt(d * d + r * r) << endl;
    return 0;

}
