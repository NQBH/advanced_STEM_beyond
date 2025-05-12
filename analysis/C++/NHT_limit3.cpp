#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon;
    cout << "Nhap epsilon (ε > 0): ";
    cin >> epsilon;

    if (epsilon <= 0) {
        cout << "ε phai lon hon 0." << endl;
        return 1;
    }

    int n = 0;
    while ((n + 1) / pow(3, n) >= epsilon) {
        ++n;
        if (n > 1000) {
            cout << "Khong tim thay trong 1000 buoc." << endl;
            return 1;
        }
    }

    cout << "Gia tri N_epsilon toi uu la: " << n << endl;
    return 0;
}