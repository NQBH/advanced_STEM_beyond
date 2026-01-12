#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float dai, rong;

    cout << "Nhap chieu dai: ";
    cin >> dai;
    cout << "Nhap chieu rong: ";
    cin >> rong;

    float chuVi = 2 * (dai + rong);
    float dienTich = dai * rong;
    float duongCheo = sqrt(dai * dai + rong * rong);

    cout << "Chu vi hinh chu nhat: " << chuVi << endl;
    cout << "Dien tich hinh chu nhat: " << dienTich << endl;
    cout << "Do dai duong cheo: " << duongCheo << endl;

    return 0;
}
