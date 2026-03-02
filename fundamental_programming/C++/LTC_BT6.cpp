#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    const double EPS = 1e-9;

    cin >> a >> b >> c;

    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS)
                cout << "Phuong trinh co vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            cout << "Phuong trinh co 1 nghiem\n";
            cout << "x = " << -c / b;
        }
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta > EPS) {
        cout << "Phuong trinh co 2 nghiem phan biet\n";
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a);
    }
    else if (fabs(delta) < EPS) {
        cout << "Phuong trinh co nghiem kep\n";
        cout << "x = " << -b / (2 * a);
    }
    else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-delta) / (2 * a);
        cout << "Phuong trinh co 2 nghiem phuc\n";
        cout << "x1 = " << realPart << " + " << imagPart << "i\n";
        cout << "x2 = " << realPart << " - " << imagPart << "i";
    }

    return 0;
}
