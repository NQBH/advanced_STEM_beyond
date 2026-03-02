#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;
    cout << "nhap bien vao phuong trinh 1 (a, b, c): " << endl;
    cin >> a >> b >> c;
    cout << "nhap bien vao phuong trinh 2 (A, B, C): " << endl;
    cin >> A >> B >> C;


    double M = (a*B) - (A*b);
    double Mx = (c*B) - (C*b);
    double My = (a*C) - (A*c);

    if (M != 0) {
        cout << "he co mot nghiem: x = " << Mx / M << " ; y = " << My / M << endl;
    } else if (Mx == 0 && My == 0) {
        cout << "he co vo so nghiem" << endl;
    } else {
        cout << "he vo nghiem" << endl;
    }

}