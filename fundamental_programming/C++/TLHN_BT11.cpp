#include <iostream>
using namespace std;

int main() {
    double a;
    cout << "Nhap a: " << endl;
    cin >> a;

    double b;
    cout << "Nhap b: " << endl;
    cin >> b;
    double c;
    cout << "Nhap c: " << endl;
    cin >> c;

    double A;
    cout << "Nhap A: " << endl;
    cin >> A;

    double B;
    cout << "Nhap B: " << endl;
    cin >> B;

    double C;
    cout << "Nhap C: " << endl;
    cin >> C;

    double D;
    double Dx;
    double Dy;
    double x;
    double y;

// TINH CAC DINH THUC D, Dx, Dy

    D  = a * B - A * b;
    Dx = c * B - C * b;
    Dy = a * C - A * c;


    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;

        cout << "He phuong trinh co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else {
        if (Dx == 0 && Dy == 0)
            cout << "He phuong trinh co vo so nghiem." << endl;
        else
            cout << "He phuong trinh vo nghiem." << endl;
    }

    return 0;
}