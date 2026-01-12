#include <cmath>
#include <iostream>
using namespace std;

int main() {

    int a, b;
    cout << "Nhap do dai 2 canh cua hinh chu nhat: ";
    cin >> a >> b;

    if (a > 0 && b > 0) {
        cout << "chu vi = " << (a + b) * 2 << endl;
        cout << "dien tich = " << a * b << endl;
        cout << "duong cheo = " << sqrt(a * a + b * b) << endl;
    } else {
        cout << " Du lieu khong hop le ";
    }

    return 0;
}
