#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, chan = 0, le = 0;
    cout << "Nhap so luong so nguyen n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cout << "Nhap so thu " << i << ": ";
        cin >> x;
        if (abs(x) % 2 == 0) chan++;
        else le++;
    }
    cout << "So chan: " << chan << ", So le: " << le << endl;
    return 0;
}