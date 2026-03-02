#include <iostream>
using namespace std;
int main() {
    double a, b;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    if (a == 0) {
        if (b == 0) {
            cout << "vo so nghiem" << endl;
        } else {
            cout << "vo nghiem" << endl;
        }
    } else {
        double x = -b / a;
        cout << "x = " << x << endl;
    }
    return 0;
}
