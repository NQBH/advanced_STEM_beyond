#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "vo so nghiem";
            else
                cout << "vo nghiem";
        } else {
            cout << "co nghiem x =" << -c / b;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "vo nghiem";
        } else if (delta == 0) {
            cout << "nghiem kep x =" << -b / (2 * a);
        }
        else {
            cout << "2 nghiem phan biet:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a);
        }
    }
    return 0;
}