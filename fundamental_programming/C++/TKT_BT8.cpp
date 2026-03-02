#include <iostream>
using namespace std;

int main() {
    int n;
    float a;
    int demkhong = 0;
    int demam = 0;
    int demduong = 0;
    do {
        cout << "hay nhap n (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "n phai la so nguyen duong, vui long nhap lai!" << endl;
        }
    } while (n <= 0);
    for (int i = 1; i <= n; i++) {
        cout << "hay nhap so thu " << i << ": ";
        cin >> a;
        if (a == 0) {
            demkhong++;
        } else if (a < 0) {
            demam++;
        } else {
            demduong++;
        }
    }
    cout << "\n ket qua la:" << endl;
    cout << "so luong so 0: " << demkhong << endl;
    cout << "so luong so am: " << demam << endl;
    cout << "so luong so duong: " << demduong << endl;

    return 0;
}