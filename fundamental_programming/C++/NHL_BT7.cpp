#include <iostream>
using namespace std;
int main() {
    double a, b, c, max, mix;
    cout << "nhap so a: ";
    cin >> a ;
    cout << "nhap so b: ";
    cin >> b ;
    cout << "nhap so c: ";
    cin >> c ;
    if (a > b && a > c) {
        double max = a;
        cout << "so thuc lon nhat trong 3 so cho truoc la: " <<  max << '\n';
    }
    else {
        if (b > a && b > c) {
            double max = b;
            cout << "so thuc lon nhat trong 3 so cho truoc la: " << max << '\n';
        }
        else {
            double max = c;
            cout << "so thuc lon nhat trong 3 so cho truoc la: " <<  max << '\n';
        }
    }
    if (a < b && a < c) {
        double min = a;
        cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
    }
    else {
        if (b < a && b < c) {
            double min = b;
            cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
        }
        else {
            double min = c;
            cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
        }
    }
}



