#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c; cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0) {
        if (a == b == c) {
            cout << "HLP" << '\n';
        }
        else {
            cout << "HHCN" << '\n';
            // Gia su chieu cao cua HHCN la c
            double DTXQ = (a * c + b * c) * 2;
            double DTTP = (a * b + b * c + c * a) * 2;
            double CHEO = sqrt(a * a + b * b + c * c);
            double V = a * b * c;
            cout << "Dien tich xung quanh cua HHCN la " << DTXQ << '\n';
            cout << "Dien tich toan phan cua HHCN la " << DTTP << '\n';
            cout << "Do dai duong cheo cua HHCN la " << CHEO << '\n';
            cout << "The tich cua HHCN la " << V << '\n';
        }
    }
    else {
        cout << -1 << '\n';
    }
}