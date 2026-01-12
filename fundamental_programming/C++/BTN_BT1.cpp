#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float a;
    cout << "Nhap canh hinh vuong a: ";
    cin >> a;
    float P = 4 * a;
    cout << "Chu vi hinh vuong canh " << a << " la: " << P << '\n';
    float S = a * a;
    cout << "Dien tich hinh vuong canh " << a << " la: " << S << '\n';

    return 0;
}