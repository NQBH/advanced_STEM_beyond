#include <iostream>
#include <cmath>
using namespace std;


float a, b, c;

int main() {


    cout << "GIAI PHUONG TRINH BAC HAI" << endl;

    cout << "Nhap so a: ";
    cin >> a;


    cout << "Nhap so b: ";
    cin >> b;

    cout << "Nhap so c: ";
    cin >> c;


    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh tren vo nghiem" << endl;
            }
        }
        else {
            float x = - c / b;

            cout << "Phuong trinh co so nghiem x = " << x << endl;
        }
    }

    else {
        float delta = pow(b, 2) - 4 * a * c;


        if (delta > 0) {

            float x1 = ( - b + sqrt(delta)) / (2 * a);


            float x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;

            cout << "x1 = " << x1 << endl;

            cout << "x2 = " << x2 << endl;
        }

        else if ( delta == 0 ) {

            float x = - b / ( 2 * a );

            cout << "Phuong trinh co nghiem kep x = " << x << endl;
        }


        else {

            float phanNghiemThuc = - b / ( 2 * a );

            float phanNghiemAo = sqrt ( -delta ) / ( 2 * a );


            cout << "Phuong trinh co 2 nghiem phuc:" << endl;

            cout << "x1 = " << phanNghiemThuc << " + " << phanNghiemAo << "i" << endl;

            cout << "x2 = " << phanNghiemThuc << " - " << phanNghiemAo << "i" << endl;
        }
    }

    return 0;
}

