#include <iostream>
using namespace std;
int main() {
    double a, b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0)
            cout << "Vo so nghiem";
        else
            cout << "Vo nghiem";
    } else {
        double x = -b / a;
        cout << x;
    }
}