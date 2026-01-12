#include<iostream>
#include<cmath>
using namespace std;
int main () {
    float chieudai, chieurong;
    cout << "Nhap vao chieu dai hinh chu nhat:" << endl;
    cin >> chieudai;
    cout << "Nhap vao chieu rong hinh chu nhat:" << endl;

    cin >> chieurong;

    float chuvi = 2 * (chieudai + chieurong);
    float dientich = chieudai * chieurong;
    float duongcheo = sqrt (chieudai * chieudai + chieurong * chieurong );



    cout << "chu vi cua hinh chu nhat:" << chuvi << endl;
    cout << "dien tich cua hinh chu nhat:" << dientich << endl;
    cout << "duong cheo cua hinh chu nhat:" << duongcheo << endl;

    return 0;
}
