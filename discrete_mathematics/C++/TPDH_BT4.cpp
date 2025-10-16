#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;
    if (pow(2, n)>= 100)
    cout << "Bat dang thuc 2^n >= 100 la DUNG." << '\n';
    else
    cout << "Bat dang thuc 2^n >= 100 la SAI." << '\n';
    return 0;
}