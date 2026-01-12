#include <iostream>
#include <cmath>
using namespace std;

int main (){
    double a, b ;
    cout << "nhap a, b: " ;
    cin >> a >> b ;
    cout << "giai phuong trinh ax + b = 0" << endl ;
    if (a == 0 ){
        if (b == 0 ){
            cout << "phuong trinh vo so nghiem " << endl ;
        } else {
            cout << "phuong trinh vo nghiem " << endl ;
        }
    } else {
        double x = -b / a ;
        cout << "phuong trinh co nghiem x = " << x << endl ;
    }
    return 0 ;
}