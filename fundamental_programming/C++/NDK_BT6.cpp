#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double a, b, c;
    cout << "Nhap he so a";
    cin >> a;

    cout << "Nhap he so b";
    cin >> b;

    cout << "Nhap he so c";
    cin >> c;
    cout << "ket qua phuong trinh bac hai:" << "a " << "x^2 + " << " bx +" << " c=" << " 0" << endl;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh vo so nghiem:" << endl;
            } else {
                cout << "Phuong trinh vo nghiem:" << endl;
            }
        } else {
            cout << "Phuong trinh có mot nghiem:" << -c / b << endl;

        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = ( -b + sqrt (delta)) / (2 * a);
            double x2 = ( -b - sqrt (delta)) / (2 * a);
            cout << "Phuong trinh co hai nghiem phan biet:" << endl;
            cout << "x1" << x1 << endl;
            cout << "x2" << x2 << endl;
        } else {
            if (delta == 0) {
                double x = -b / (2 * a);
                cout << "Phuong trinh co nghiem kep:" << -b / (2 * a) << endl;
            } else {
                double phanthuc = -b / (2 * a);
                double phanao = sqrt(abs(delta)) / (2 * a);
                cout << "Phuong trinh co hai nghiem phuc:" << endl;
                cout << "x1" << "=" << phanthuc << " + " << phanao << " i " << endl;
                cout << "x2" << "=" << phanthuc << " - " << phanao << " i " << endl;
            }
        }
    }
    return 0;
}

