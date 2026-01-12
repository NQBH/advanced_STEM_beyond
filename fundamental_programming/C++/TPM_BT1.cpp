#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float canh, C, S;
    cout << "Nhap canh hinh vuong ";
    cin >> canh;
    C = canh * 4;
    S = pow(canh, 2);
    cout << "Chu vi = " << C << '\n';
    cout << "Dien tich = " << S << '\n';
    return 0;
}