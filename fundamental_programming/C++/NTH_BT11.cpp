#include <iostream>
#include <iomanip>
using namespace std;

void giaiHePhuongTrinh(double a, double b, double c, double A, double B, double C) {
    cout << "\n===== HE PHUONG TRINH =====\n";
    cout << "{ " << a << "x + " << b << "y = " << c << endl;
    cout << "{ " << A << "x + " << B << "y = " << C << endl;
    cout << "\n===== GIAI =====\n";

    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:\n";
        cout << fixed << setprecision(2);
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem (phuong trinh phu thuoc tuyen tinh)\n";

            if (b != 0) {
                cout << "Nghiem tong quat: x = t, y = (" << c << " - " << a << "t) / " << b << endl;
                cout << "(Voi t la tham so bat ky)\n";
            } else if (B != 0) {
                cout << "Nghiem tong quat: x = t, y = (" << C << " - " << A << "t) / " << B << endl;
                cout << "(Voi t la tham so bat ky)\n";
            }
        }
        else {
            cout << "He vo nghiem (phuong trinh mau thuan)\n";
        }
    }
}

int main() {
    double a, b, c, A, B, C;

    cout << "===== GIAI HE PHUONG TRINH TUYEN TINH 2 AN =====\n";
    cout << "He phuong trinh co dang:\n";
    cout << "{ ax + by = c\n";
    cout << "{ Ax + By = C\n\n";

    // Nhập a,b
    cout << "Nhap he so phuong trinh thu nhat (ax + by = c):\n";
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    // Nhập A,B
    cout << "\nNhap he so phuong trinh thu hai (Ax + By = C):\n";
    cout << "Nhap A: ";
    cin >> A;
    cout << "Nhap B: ";
    cin >> B;
    cout << "Nhap C: ";
    cin >> C;

    // Gọi hàm giải hệ phương trình
    giaiHePhuongTrinh(a, b, c, A, B, C);

    return 0;
}