#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;

    if (pow(2, n) >= 100)
        cout << "Đ" << endl;  // Đúng
    else
        cout << "S" << endl;  // Sai

    return 0;
}