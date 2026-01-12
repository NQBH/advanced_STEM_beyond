#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int chieudai;
    int chieurong;
    cout << "Nhap chieu dai:";
    cin >> chieudai;
    cout << "Nhap chieu rong:";
    cin >> chieurong;

    float ChuVi = (chieudai + chieurong) *2;
    float DienTich = chieudai * chieurong;
    float DuongCheo = sqrt(chieudai*chieudai + chieurong*chieurong);

    cout << "Chu vi hinh chu nhat bang:" << ChuVi << endl;
    cout << "Dien Tich hinh chu nhat bang:" << DienTich << endl;
    cout << "Duong Cheo hinh chu nhat bang:" << DuongCheo << endl;

    return 0;
}
