#include <iostream>
using namespace std;

int main() {
    double a,b;
    cin >> a >> b;
    cout << "nhap a: " << a << endl;
    cout << "nhap b: " << b << endl;

    if ( a == 0){
        if ( b == 0) {
            cout << "phuong trinh vo so nghiem" << endl;
        } else {
            cout << "phuong trinh vo nghiem" << endl;
        }
    } else {
        double x = -b/a;
        cout << "phuong trinh co nghiem x la: " << x << endl;
    }
    return 0;
}
