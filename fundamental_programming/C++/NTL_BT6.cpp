#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double Delta = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0) {
        cout << "INFINITE SOLUTIONS";
    }
    else if (a == 0 && b == 0) {
        cout << "NO SOLUTION";
    }
    else if (a == 0) {
        double x = -c / b;
        cout << "co 1 nghiem" << x;
    }
    else if (Delta < 0) {
        cout << "NO SOLUTION";
    }
    else if (Delta == 0) {
        double x1 = -b / (2 * a);
        cout << "co nghiem kep" << x1;
    }
    else {
        double x2 = (-b + sqrt(Delta)) / (2 * a);
        double x3 = (-b - sqrt(Delta)) / (2 * a);
        cout << "co 2 nghiem phan biet";
        cout << x2;
        cout << x3;
    }
    return 0;
}