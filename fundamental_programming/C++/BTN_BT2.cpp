#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float dai, rong;
    cout << "Nhap chieu dai: ";
    cin >> dai;
    cout << "Nhap chieu rong: ";
    cin >> rong;
    float P = (dai + rong) * 2;
    cout << "Chu vi hinh chu nhat la: " << P << '\n';
    float S = dai * rong;
    cout << "Dien tich hinh chu nhat la: " << S << '\n';
    float D = sqrt(pow(dai, 2) + pow(rong, 2));
    cout << "Do dai duong cheo la: " << D << '\n';

    return 0;
}