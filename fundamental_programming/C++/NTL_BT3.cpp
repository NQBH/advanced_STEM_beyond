#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > 0 && a == b && b == c) {
        cout << "HLP";
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN";
        int tt = a * b * c;
        int dtXQ = 2 * (a + b) * c;
        int dtTP = 2 * (a * b + b * c + a * c);
        int dc = sqrt(a * a + b * b + c * c);
        cout << "Dien tich xung quanh: " << dtXQ;
        cout << "Dien tich toan phan: " << dtTP;
        cout << "Duong cheo: " << dc;
        cout << "The tich: " << tt;
    }
    else {
        cout << -1;
    }
    return 0;
}