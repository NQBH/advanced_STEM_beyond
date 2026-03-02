#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        float a, b, c, delta, x1, x2;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    cout << "Phuong trinh vo so nghem" << '\n';
                } else {
                    cout << "Phuong tinh vo nghiem" << '\n';
                }
            } else {
                cout << "Co mot nghiem" << -c / b << '\n';
            }
        } else {
            delta = b * b - 4 * a * c;
            if (delta > 0) {
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);
                cout << "Nghiem thu nhat x1 = " << x1 << '\n';
                cout << "Nghiem thu hai x2 = " << x2 << '\n';
            } else if (delta < 0) {
                cout << "Phuong trinh vo nghiem" << '\n';
            } else if (delta == 0) {
                cout << "Phuong trinh co nghiem kep" << -b / 2 * a << '\n';
            } else {
                cout << "Phuong trinh vo nghiem" << '\n';

            }
        }
    }
    return 0;
}
