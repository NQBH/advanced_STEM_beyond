#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    const float a = 23;
    const float b = 12;
    const float c = 16;

    // Kiem tra hinh lap phuong
    if (a > 0 && a == b && b == c )
        cout << "HLP";
    // Kiem tra hinh hop chu nhat
    else if (a > 0 && b > 0 && c > 0)
        cout << "HHCN" << endl;

    int DientichXQ = 2 * c * (a + b);
    int DientichTP = (a + b) * 2 * c + 2 * a * b;
    double Duongcheo = sqrt(a * a + b * b + c * c);
    int Thetich = a * b * c;

    cout << "Dien tich xung quanh: " << DientichXQ << endl;
    cout << "Dien tich toan phan: " << DientichTP << endl;
    cout << "Duong cheo: " << Duongcheo << endl;
    cout << "The tich: " << Thetich << endl;

    return 0;
}