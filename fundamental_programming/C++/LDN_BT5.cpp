#include<iostream>
using namespace std;
int main() {
    double a, b;
    cout << "Giai phuong trinh bac nhat: ax + b = 0" << endl;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    if (a == 0) {
        if (b == 0){
            cout << "phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "phuong trinh vo nghiem." << endl;
        }
    } else {
        double x = -b / a;
        cout << "phuong trinh co nghiem duy nhat x = " << x << endl;
    }
}