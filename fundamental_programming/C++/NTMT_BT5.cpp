#include <iostream>
using namespace std;
int main() {
    float a, b; cin >> a >> b;
    if (a != 0 ) {
        if (b == 0) cout << "x = 0" << endl;
        else cout << "x= " << -b / a << endl;
    }
    else {
        if (b == 0) cout << "phuong trinh co vo so nghiem" << endl;
        else cout << "phuong trinh vo nghiem" << endl;
    }
}