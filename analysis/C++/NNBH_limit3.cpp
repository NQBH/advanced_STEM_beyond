#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon;
    cout << "Nhap so epsilon: ";
    cin >> epsilon;

    int n = 0;
    double an = (n + 1) / pow(3.0, n);

    while (an >= epsilon) {
        n++;
        an = (n + 1) / pow(3.0, n);
    }

    cout << "Gia tri n nho nhat sao cho |a_n| < epsilon la: " << n << endl;

    return 0;
}