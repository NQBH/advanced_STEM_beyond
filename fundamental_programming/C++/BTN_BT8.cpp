#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, am = 0, duong = 0, zero = 0;
    cout << "Nhap so luong n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        float x;
        cout << "Nhap so thu " << i << ": ";
        cin >> x;
        if (x > 0) duong++;
        else if (x < 0) am++;
        else zero++;
    }
    cout << "Ket qua: " << duong << " so duong, " << am << " so am, " << zero << " so 0" << endl;
    return 0;
}