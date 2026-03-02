#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhập 3 số thực : " ; cin >> a >> b >> c;
    cout << "Phương trình ta có : " << a << "x^2 + " << b << "x + " << c << " = 0" << '\n';
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {cout << "Phương trình có vô số nghiệm";}
        }
        else {cout << "Phương trình vô nghiệm";}
    }
    else {
        double delta = pow(b, 2) - 4 * a * c;
        if (delta < 0) {
            cout << "Phương trình vô nghiệm";
        }
        else if (delta == 0) {
            cout << "Phương trình có 1 nghiệm kép x = " << -b / (2 * a) << '\n';
        }
        else if (delta > 0) {
            cout << "Phương trình có 2 nghiệm phân biệt :";
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 =  (-b + sqrt(delta)) / (2 * a);
            cout << "x1 = " << x1 << " và x2 = " << x2 << '\n';
        }
    }
}