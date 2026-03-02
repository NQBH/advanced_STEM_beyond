#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    double A, B, C;
    
    cout << "Giai he pt:\n ax + by = c\n Ax + By = C\n";
    cout << "___________________________\n";
    
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    cout << "Xac nhan:" << "a = " << a << ", b = " << b << ", c = " << c << endl;

    cout << "Nhap A, B, C: ";
    cin >> A >> B >> C;
    cout << "Xac nhan:" << "A = " << A << ", B = " << B << ", C = " << C << endl;

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    cout << "___________________________\n";
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He phuong trinh co 1 nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } 
    else {
        if (Dx != 0 || Dy != 0) {
            cout << "He phuong trinh vo nghiem" << endl;
        } 
        else {
            cout << "He phuong trinh vo so nghiem" << endl;
        }
    }

    return 0;
}