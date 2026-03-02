#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a,b,c;
    cout << "Nhap he so a,b,c: ";
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh co 1 nghiem x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem thuc phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep x = " << x << endl;
        } else {
            double phanThuc = -b / (2 * a);
            double phanAo = sqrt(abs(delta)) / (2 * a);
            cout << "Phuong trinh vo nghiem thuc, co 2 nghiem phuc:" << endl;
            cout << "x1 = " << phanThuc << " - " << abs(phanAo) << "i" << endl;
            cout << "x2 = " << phanThuc << " + " << abs(phanAo) << "i" << endl;
        }
    }
}