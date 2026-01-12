#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float a, b;
    cout << "Nhap do dai canh chu nhat:";
    cin >> a >> b;
    float chuvi = 2 * (a + b);
    float dientich = a * b;
    float duongcheo = sqrt(a * a + b * b);
    cout << "chu vi hinh chu nhat la: " << chuvi << endl;
    cout << "dien tich hinh chu nhat la: " << dientich << endl;
    cout << "duong cheo hinh chu nhat la: " << duongcheo << endl;
    return 0;
}
