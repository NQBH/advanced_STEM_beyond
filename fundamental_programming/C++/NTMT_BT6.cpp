#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c; cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0) {
            if (c == 0) cout << "x= 0" << endl;
            else cout << "x= " << -c / b << endl;
        }
        else {
            if (c == 0) cout << "phuong trinh co vo so nghiem" << endl;
            else cout << "phuong trinh vo nghiem" << endl;
        }
    }
    else {
        float del = b * b - 4 * a * c;
        float thuc = -b / (2 * a), ao = sqrt(abs(del)) / (2 * a);
        if (del > 0) {
            cout << "x1= " << thuc + ao << endl;
            cout << "x2= " << thuc - ao << endl;
        }
        else if (del == 0) cout << "x= " << thuc << endl;
        else {
            ao = abs(ao);
            cout << "x1= " << thuc << "+" << ao << "i" << endl;
            cout << "x2= " << thuc << "-" << ao << "i" << endl;
        }
    }
}