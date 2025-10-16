#include <iostream>
using namespace std;

int main() {
    double n;
    cout << "Nhap gia tri cua n (so thuc):" ;
    cin >> n;
    if (2 ^ n >= 100)
        cout << "2^n >= 100 là đúng"  << '\n';
    else
        cout << "2^n >= 100 là sai" << '\n';
}