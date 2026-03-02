#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "vo so nghiem." << '\n';
            } else {
                cout << "vo nghiem." << '\n';
            }
        } else {
            cout << "co nghiem duy nhat: x = " << -c / b << '\n';
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "2 nghiem phan biet:" << '\n';
            cout << "x1 = " << x1 << '\n';
            cout << "x2 = " << x2 << '\n';
        }
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "co nghiem kep: " << x << '\n';
        }
        else {
            double thuc = -b / (2 * a);
            double ao = sqrt(abs(delta)) / (2 * a);
            cout << "co nghiem phuc:" << '\n';
            cout << "x1 = " << thuc << " + " << abs(ao) << "i" << '\n';
            cout << "x2 = " << thuc << " - " << abs(ao) << "i" << '\n';
        }
    }

    return 0;
}
