#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //  phương trình bậc nhất ax + b = 0
   double a = 3;
   double b = 5;

    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";
    cin >> b;

    cout << "\nPhuong trinh ban vua nhap: " << a << "x + " << b << " = 0" << endl;

    if (a != 0) {
        
        double x = -b / a;
        cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
    } 
    else {
        
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    }

    return 0;
}