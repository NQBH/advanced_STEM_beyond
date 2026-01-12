#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > 0 && b > 0 && c > 0) {
        if (a == b && a == c) {
            cout << "HLP" << '\n';
        } else {
            cout << "HHCN" << '\n';
            int Sxq, Stp, V;
            float Dc;
            V = a * b * c;
            Sxq = 2 * (a + b) * c;
            Stp = Sxq + 2 * a * b;
            Dc = sqrt(pow(sqrt(pow(a, 2) + pow(b, 2)), 2) + pow(c, 2));
            cout << "Dien tich xung quanh = " << Sxq << '\n';
            cout << "Dien tich toan phan = " << Stp << '\n';
            cout << "Duong cheo = " << Dc << '\n';
            cout << "The tich = " << V << '\n';
        }
    } else {
        cout << -1;
    }
    return 0;
}