#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main () {
    double a , b , c ;
    cout << "nhap a , b , c: " ;
    cin >> a >> b >> c ;
    cout << "giai phuong trinh bac 2 ax^2 + bx + c = 0" << endl ;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh co 1 nghiem thuc: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem." << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b / (2 * a) << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet: " << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            
        }
    }
    // Bonus +1: Giai phuong trinh bac 2 co nghiem phuc
        double delta = b * b - 4 * a * c;
      if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem thuc phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } 
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep thuc: x = " << x << endl;
        } 
        else {
            // Truong hop Delta < 0: Nghiem phuc (Bonus +1)
            double phanThuc = -b / (2 * a);
            double phanAo = sqrt(-delta) / (2 * a);
            
            cout << "Phuong trinh co 2 nghiem phuc:" << endl;
            // Nghiem phuc co dang: a + bi va a - bi
            cout << "x1 = " << phanThuc << " + " << abs(phanAo) << "i" << endl;
            cout << "x2 = " << phanThuc << " - " << abs(phanAo) << "i" << endl;
        }
}