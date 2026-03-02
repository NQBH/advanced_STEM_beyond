#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;

    if (a == 0 && b == 0) {
        cout << "vo so nghiem" << '\n';
    }
    else if (a == 0 && b != 0) {
        cout << "vo ngiem" << '\n';
    }
    else {
        cout << "x = " << -b / a << '\n';
    }
}