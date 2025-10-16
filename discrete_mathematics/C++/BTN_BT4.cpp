#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;

    double ketqua = pow(2, n);

    cout << "Gia tri 2^n = " << ketqua << endl;

    if (ketqua >= 100)
        cout << "B bat dang thuc 2^n >= 100 la DUNG." << endl;
    else
        cout << "B bat dang thuc 2^n >= 100 la SAI." << endl;

    return 0;
}