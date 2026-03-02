#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    double A, B, C; 

    cout << "Giải Phương Trình Hệ Tuyến Tính" << endl;
    cout << "Nhập a, b, c (PT1: ax + by = c): ";
    cin >> a >> b >> c;

    cout << "Nhập A, B, C (PT2: Ax + By = C): ";
    cin >> A >> B >> C;

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "Hệ Phương Trình Có Nghiệm Duy Nhất: " << endl;
        cout << "   x = " << x << endl;
        cout << "   y = " << y << endl;
    } else {
        if (Dx != 0 || Dy != 0) {
            cout << "Hệ Phương trình vô Nghiệm (hai đường thẳng song song)." << endl;
        } else {
            cout << "Hệ Phương trình vô số Nghiệm (hai đường thẳng Trùng nhau)." << endl;
        }
    }

    return 0;
}