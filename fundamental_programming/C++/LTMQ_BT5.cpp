#include <bits/stdc++.h>
using namespace std;

int main() {

    int a , b;
    cout << "nhap a = ";
    cin >> a;
    cout << "nhap b = ";
    cin >> b;
    if (a != 0) {
        float x = -b / a;
        cout << "phuong trinh co nghiem =" << x;
    }
    else {
        if (b == 0) cout << "phuong trinh vo so nghiem";
        else cout << "phuong trinh khong co nghiem";
    }
    return 0;
}
