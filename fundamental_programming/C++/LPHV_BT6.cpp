#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem" << endl;
            else
                cout << "Phuong trinh vo nghiem" << endl;
        } else {
            double x = -c / b;
            cout << "Phuong trinh bat nhat co nghiem x = " << x << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << " x1 = " << x1 << endl;
            cout << " x2 = " << x2 << endl;
        }
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << x << endl;
        }
        else {
            double real = -b / (2 * a);
            double imag = sqrt(-delta) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phuc" << endl;
            cout << " x1 = " << real << " + " << imag << "i" << endl;
            cout << " x2 = " << real << " - " << imag << "i" << endl;
        }
    }
}