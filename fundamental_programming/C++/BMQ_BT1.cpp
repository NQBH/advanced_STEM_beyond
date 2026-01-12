#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Nhap do dai canh hinh vuong: ";
    cin >> a;

    if (a > 0) {
        cout << "Chu vi = " << a * 4 << endl;
        cout << "Dien tich = " << a * a << endl;
    } else {
        cout << " Du lieu khong hop le ";
    }

    return 0;
}