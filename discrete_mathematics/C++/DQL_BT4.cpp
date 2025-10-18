#include <iostream>

using namespace std;

int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;

    double value = pow(2, n); // 2^n

    if (value >= 100) {
        cout << "Dung: 2^n >= 100" << endl;
    } else {
        cout << "Sai: 2^n < 100" << endl;
    }

    return 0;
}
