#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > 0 && a == b && b == c) {
        cout << "HLP";
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;

        int Sxq = 2 * c * (a + b);
        int Stp = 2 * (a * b + b * c + a * c);
        double d = sqrt(a * a + b * b + c * c);
        int V = a * b * c;

        cout << "Dien tich xung quanh: " << Sxq << endl;
        cout << "Dien tich toan phan: " << Stp << endl;
        cout << "Duong cheo: " << d << endl;
        cout << "The tich: " << V;
    }
    else {
        cout << -1;
    }

    return 0;
}