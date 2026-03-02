#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cout << "nhap bien phuong trinh 1 (a, b, c): " << endl;
    cin >> a >> b >> c;
    cout << "nhap bien phuong trinh 2 (A, B, C): " << endl;
    cin >> A >> B >> C;

//tinh 3 dinh thuc
    //he: ax + by = c
    //    Ax + By = C
    double D = (a*B) - (A*b);
    double Dx = (c*B) - (C*b);
    double Dy = (a*C) - (A*c);

    //TH1
    if (D != 0) {
        cout << "he co mot nghiem: x = " << Dx / D << " ; y = " << Dy / D << endl;
    } else if (Dx == 0 && Dy == 0) {
        cout << "he co vo so nghiem" << endl;
    } else {
        cout << "he vo nghiem" << endl;
    }

}