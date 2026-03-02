//Bai Tap 5
#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b;
    cin >> a >> b;
    cout << "Nhap a=";
    cout << "Nhap b=";
    if ( a == 0 ) {
        if ( b == 0) {
            cout << "Phuong trinh da cho co vo so nghiem" << endl;
        } else {
            cout << "Phuong trinh da cho vo nghiem" << endl;
        }
    } else {
        double x = -b / a;
        cout << "Phuong trinh da cho co nghiem x =" << x << endl;
    }
    return 0;
}