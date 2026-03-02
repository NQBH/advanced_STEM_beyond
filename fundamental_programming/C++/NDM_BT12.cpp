#include <iostream>
#include <cmath>
using namespace std;
// tính Sm = 1^m + 2^m + 3^m + ... + n^m với m là số nguyên nhập vào từ bàn phím.
int main() {
    int n, m;
    double S = 0;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        S += pow(i, m);
        
    }

    cout << "S = " << S << endl;

    return 0;
}