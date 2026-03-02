#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b, c, A, B, C;
    cout << "Nhap a, b, c= ";
    cin >> a >> b >> c;
    cout << "Nhap A, B, C= ";
    cin >> A >> B >> C;

    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0){
        double x = Dx / D;
        double y = Dy / D;
        cout << "He phuong trinh co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He phuong trinh co vo so nghiem" << endl;
        } else {
            cout << "He phuong trinh vo nghiem" << endl;
        }
    }
    return 0;
}