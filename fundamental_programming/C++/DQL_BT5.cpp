#include <iostream>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh vo so nghiem";
        else
            cout << "Phuong trinh vo nghiem";
    } else {
        float x = -b / a;
        cout << "Nghiem cua phuong trinh la: x = " << x;
    }

    return 0;
}