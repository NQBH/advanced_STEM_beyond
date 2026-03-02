#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c;
    cout << "Nhập a: ";
    cin >> a;
    cout << "Nhập b: ";
    cin >> b;
    cout << "Nhập c: ";
    cin >> c;
    //Hiển thị
    cout << "Phương trình: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0" << endl;
    //Giải
    if (a == 0) {
        //Trường hợp phương trình bậc nhất: bx + c = 0
        cout << "Đây là phương trình bậc nhất" << endl;
        if (b == 0) {
            if (c == 0) {
                cout << "Phương trình có vô số nghiệm" << endl;
            } else {
                cout << "Phương trình vô nghiệm" << endl;
            }
        } else {
            double x = -c / b;
            cout << "Nghiệm: x = " << x << endl;
        }
    } else {
        //Trường hợp phương trình bậc 2: ax^2 + bx + c = 0
        double delta = b * b - 4 * a * c;
        cout << "Delta = b^2 - 4ac = " << delta << endl;
        if (delta > 0) {
            //Trường hợp 2 nghiệm phân biệt
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phương trình có 2 nghiệm phân biệt: " << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            //Trường hợp nghiệm kép
            double x = -b  / (2 * a);
            cout << "Phương trình có nghiệm kép: " << endl;
            cout << "x1 = x2 = " << x << endl;
        } else {
            //Trường hợp nghiệm phức
            //Khi delta < 0 nên sqrt delta không tồn tại -> nghiệm sẽ là số phức
            //Công thức: z = a(phần thực) + bi (phần ảo) [i là đơn vị ảo]
            double thuc = -b / (2 * a);
            double ao = sqrt(-delta) / (2 * a);
            cout << "Phương trình có 2 nghiệm phức: " << endl;
            cout << "x1 = " << thuc << " + " << ao <<  "i" << endl;
            cout << "x2 = " << thuc << " + " << ao << "i" << endl;
        }
    }
    return 0;
}