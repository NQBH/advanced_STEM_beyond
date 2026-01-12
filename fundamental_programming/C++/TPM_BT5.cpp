#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if (a != 0) {
        cout << a << "x + " << b << " = 0" << '\n';
        cout << "x = " << -b / a << '\n';
    }
}