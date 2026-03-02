#include<iostream>
using namespace std;
int main() {
    double a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo vo nghiem";
        } else {
            cout << "Phuong trinh vo nghiem";
        }
    } else {
        double x = -b / a;
        cout << "Phuong trinh co nghiem x la " << x << endl;
    }
}

