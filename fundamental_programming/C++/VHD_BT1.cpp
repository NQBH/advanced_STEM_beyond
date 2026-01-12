#include <iostream>
using namespace std;

int main() {
    float a;
    cout << "Nhap canh hinh vuong: ";
    cin >> a;

    float chuVi = 4 * a;
    float dienTich = a * a;

    cout << "Chu vi hinh vuong = " << chuVi << endl;
    cout << "Dien tich hinh vuong = " << dienTich << endl;

    return 0;
}