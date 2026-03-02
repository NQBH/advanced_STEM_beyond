#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double a, b, c, A, B, C;
    cout << "Nhap he so a, b, c, A, B, C: " << endl;
    cin >> a >> b >> c >> A >> B >> C;
    
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0){
        cout << fixed << setprecision(2) ;
        cout << "nghiem duy nhat\n";
        cout << "x = " << Dx / D << endl;
        cout << "y = " << Dy / D << "\n";
    }
    else {
        if (Dx == 0 && Dy == 0){
            cout << "he phuong trinh vo so nghiem\n";
        }
        else {
            cout << "he phuong trinh vo nghiem\n";
        }
    }
    return 0;
}