#include <iostream>
using namespace std;

int main () {
    double a,b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) {
         cout << "Vo so nghiem" << endl;
        } else {
            cout << "Vo nghiem" << endl;
        }
    } else cout << "x = " << -b / a << endl;
    
}