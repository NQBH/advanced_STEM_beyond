#include <iostream>
using namespace std;

int main() {

    float a, b;
    float x;



    cout << "GIAI PHUONG TRINH BAC NHAT" << endl;

    cout << "Nhap so a: ";
    cin >> a;


    cout << "Nhap so b: ";
    cin >> b;


    if (a == 0) {

        if (b == 0) {

            cout << "Phuong trinh co vo so nghiem." << endl;

        } else {

            cout << "Phuong trinh vo nghiem." << endl;
        }
    } else {
        x = - b / a;

        cout << "Phuong trinh co nghiem x = " << x << endl;
    }

    return 0;
}
