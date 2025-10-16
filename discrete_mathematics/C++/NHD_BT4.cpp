#include <iostream>
#include <cmath>  // Thu vi?n cho hàm pow()

using namespace std;

int main() {
    double n;
    cout << "Nhap vao so thuc n: ";
    cin >> n;

    double giatri = pow(2, n);  // Tính 2^n

    // Ki?m tra b?t d?ng th?c
    if (giatri >= 100) {
        cout << "Dung" << endl;
    } else {
        cout << "Sai" << endl;
    }

    return 0;
}
