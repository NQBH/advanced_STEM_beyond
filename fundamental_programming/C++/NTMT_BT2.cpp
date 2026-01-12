#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float dai, rong;
    cin >> dai >> rong;
    if (dai > 0 && rong > 0) {
        double C = (dai + rong) * 2;
        double S = dai * rong;
        float cheo = sqrt(dai * dai + rong * rong);
        cout << "Chu vi cua hinh chu nhat la " << C << '\n';
        cout << "Dien tich cua hinh chu nhat la " << S << '\n';
        cout << "Do dai duong cheo hinh chu nhat la " << cheo << '\n';
    }
    else {
        cout << "Vui long nhap so thuc duong \n";
    }
}