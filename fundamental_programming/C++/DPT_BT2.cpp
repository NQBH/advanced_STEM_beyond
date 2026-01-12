#include <cmath>
#include <iostream>
using namespace std;

int main()
{

    float a; // a la chieu dai
    cout << "chieu dai hinh chu nhat a = " << '\n';
    cin >> a;
    float b; // b la chieu rong
    cout << "chieu rong hinh chu nhat b = " << '\n';
    cin >> b;
    // Chu vi hinh chu nhat
    float P = (a + b) * 2;
    cout << "chu vi cua hinh chu nhat la " << P << '\n';

    // Dien tich hinh chu nhat
    float S = a * b;
    cout << "dien tich cua hinh chu nhat la " << a << " nhan " << b << " bang " << S << '\n';
    // Do dai duong cheo hinh chu nhat
    float d = sqrt(a * a + b * b); // d la ky hieu cua do dai duong cheo
    cout << "do dai duong cheo cua hinh chu nhat la " << d << '\n';
}