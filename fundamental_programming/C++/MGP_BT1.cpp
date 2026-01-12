#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int canh;
    cout << "Nhap canh:";
    cin >> canh;

    float ChuVi = 4*canh;
    float DienTich = canh*canh;

    cout << "Chu vi hinh vuong bang:" << ChuVi << endl;
    cout << "Dien Tich hinh vuong bang:" << DienTich << endl;

    return 0;
}
