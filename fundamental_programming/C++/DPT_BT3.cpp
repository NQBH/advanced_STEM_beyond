#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "nhap canh a: "; //a la chieu dai
    cin >> a;
    cout << "nhap canh b: "; //b la chieu rong
    cin >> b;
    cout << "nhap canh c: "; //c la chieu cao
    cin >> c;
    if (a == b == c) {
        cout << " HLP ";
    }
    else {
        cout << " HHCN " << '\n';

// Dien tich xung quanh
        float S = (a + b) * 2 * c; //S la ky hieu dien tich xung quanh
        cout << " dien tich xung quanh = " << S << '\n';
// Dien tich toan phan
        float R = 2 * (a * b + b * c + a * c); //R la ky hieu dien tich toan phan
        cout << " dien tich toan phan = " << R << '\n';
// Duong cheo
        float D = sqrt(a * a + b * b + c * c); //D la ky hieu duong cheo
        cout << " duong cheo = " << D << '\n';
// The tich
        float V = a * b * c; //V la ky hieu the tich
        cout << " the tich = " << V << '\n';
    }

}