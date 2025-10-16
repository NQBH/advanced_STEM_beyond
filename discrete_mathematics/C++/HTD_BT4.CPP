#include <iostream>
#include <cmath> // dùng cho pow
using namespace std;

int main() {
    double n;

    // Nhập số thực n
    cout << "Nhap so thuc n: ";
    cin >> n;

    // Kiểm tra bất đẳng thức
    if (pow(2, n) >= 100)
        cout << "D" << endl; // Đúng
    else
        cout << "S" << endl; // Sai

    return 0;
}