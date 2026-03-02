#include <iostream>
#include <cmath>
using namespace std;

long long tinhSm(int n, int m) {
    long long sum = 0;
    
    for (int i = 1; i <= n; i++) {
        sum += pow(i, m);
    }
    return sum;
}
int main() {
    int n, m;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    if (n < 1) {
        cout << "n phai la so nguyen duong!" << endl;
        return 1;
    }
    long long ketQua = tinhSm(n, m);
    cout << "Sm = 1^" << m << " + 2^" << m << " + ... + " << n << "^" << m << " = " << ketQua << endl;
    return 0;
}