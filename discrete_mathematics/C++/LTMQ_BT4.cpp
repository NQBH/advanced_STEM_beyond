#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap n: ";
    cin >> n;

    bool result = pow(2, n) >= 100;
    cout << "Menh de 2^n >= 100 la " << (result ? "Dung" : "Sai") << endl;

    return 0;
}