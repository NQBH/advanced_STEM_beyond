#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;
    if (a != 0) {
        cout << a << "x+ " << b << "= 0" << endl;
        cout << "x= " << -b / a << endl;
    }
    return 0;
}