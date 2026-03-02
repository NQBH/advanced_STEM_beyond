#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b;
    cout << "Nhập a: ";
    cin >> a;
    cout << "Nhập b: ";
    cin >> b;
    
    cout << "Phương trình: " << a << "x + " << b << "= 0" << endl;

    if (a == 0) {
        if (b == 0) {
            cout << "Phương trình có vô số nghiệm" << endl;
        } else {
            cout << "Phương trình vô nghiệm" << endl;
        }
    } else {
        double x = -b / a;
        cout << "Phương trình có nghiệm duy nhất: x = " << x << endl;
    }
    
    return 0;
}