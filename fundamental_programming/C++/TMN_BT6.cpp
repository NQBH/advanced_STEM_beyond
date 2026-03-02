#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;

    if     (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Vo so nghiem";
            else
                cout << "Vo nghiem";
        } else {
            cout << -c / b;
        }
    } else {
        float delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Vo nghiem";
        } else if (delta == 0) {
            cout << -b / (2 * a);
        } else {
            cout << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << (-b - sqrt(delta)) / (2 * a);
        }
    }

    return 0;
}