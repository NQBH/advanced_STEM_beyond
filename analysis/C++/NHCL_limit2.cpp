#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double m;
    cout << "Nhap m (m > 0): ";
    cin >> m;

    if (m <= 0) {
        cout << "m phai lon hon 0.\n";
        return 1;
    }

    int n = 1;
    while (sqrt(n + 2) <= m) {
        n++;
    }

    cout << "Gia tri n nho nhat de sqrt(n + 2) > m la: " << n << endl;

    return 0;
}