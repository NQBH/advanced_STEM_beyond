#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c= ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            float x = -c / b;
            cout << "Phuong trinh co nghiem x = " << x;
        }
    } else {
        float deta = b * b - 4 * a * c;

        if (deta < 0) {
            cout << "Phuong trinh vo nghiem";
        } else if (deta == 0) {
            float x = -b / (2 * a);
            cout << "Phuong trinh ghiem kep x = " << x;
        } else {
            float TH1 = (-b + sqrt(deta)) / (2 * a);
            float TH2 = (-b - sqrt(deta)) / (2 * a);
            cout << "Phuong trinh 2 nghiem phan biet: ";
            cout << "TH1 = " << TH1 << endl;
            cout << "TH2 = " << TH2;
        }
    }

    return 0;
}
