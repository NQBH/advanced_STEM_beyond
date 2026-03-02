#include <bits/stdc++.h>
using namespace std;

int main() {
    float a, b;
    cout << "Nhập 2 số thực : "; cin >> a >> b;
    cout << "Phương trình ta có : " << a << "x + " << b << " = 0" << '\n';
    if (a == 0) {
        if (b == 0 ) { cout << "Phương trình có vô số nghiệm";}
        else { cout << " Phương trình vô nghiệm "; }
    }
    else {
        cout << "Phương trình có nghiệm là x = " << -b / a << '\n';
    }
}