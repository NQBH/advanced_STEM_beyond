#include <iostream>
#include <cmath>  // dùng pow() để tính 2^n
using namespace std;

int main() {
    double n;

    cout << "Nhap vao so thuc n: ";
    cin >> n;

    double ketqua = pow(2, n);  // tính 2^n

    cout << "Gia tri 2^" << n << " = " << ketqua << endl;

    if (ketqua >= 100)
        cout << "→ Bat dang thuc 2^n >= 100 la: D (Dung)" << endl;
    else
        cout << "→ Bat dang thuc 2^n >= 100 la: S (Sai)" << endl;

    return 0;
}
