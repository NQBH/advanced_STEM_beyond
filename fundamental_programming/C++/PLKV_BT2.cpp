#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float a, b;
    cout << "nhap chieu dai";
    cin >> a;
    cout << "nhap chieu rong";
    cin >> b;
    float chuvi = 2 * ( a + b );
    cout << "Chu vi = " << chuvi << endl;
    float dientich = a * b;
    cout << "Dien tich  = " << dientich << endl;
    float duongcheo = sqrt( a * a + b * b );
    cout << "Duong cheo = " << duongcheo << endl;
}