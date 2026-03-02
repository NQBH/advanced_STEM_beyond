#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b , c;
    cout << "nhap a, b, c:" << endl;
    cin >> a >> b >> c;
    cout << "ket qua: " << '\n' << endl;

    if (a == 0) {
        //bx + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "vo so nghiem" << endl;

            } else cout << "vo nghiem" << endl;
        } else cout << -c / b;

    } else {
        // ax^2 + bx + c = 0
        double delta = (b * b) - (4 * a * c);

        if (delta < 0) {
            //nghiem phuc
            double thuc = -b / (2 * a);
            double ao = sqrt(-delta) / (2 * a);

            cout << "2 nghiem phuc: " << endl;
            cout << "x1 = " << thuc << " + " << ao << "i" << endl;
            cout << "x2 = " << thuc << " - " << ao << "i" << endl;

        } else if (delta == 0) {
            cout << "nghiem kep: x = " << -b / (2 * a) << endl;

        } else {
            cout << "2 nghiem thuc:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }

}