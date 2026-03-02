#include <iostream>
using namespace std;

int main() {
    int n;
    int demduong = 0, demam = 0, demkhong = 0;
    double val;

    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> val;
        if (val > 0) {
            demduong++;
        }
        else if (val < 0) {
            demam++;
        }
        else {
            demkhong++;
        }
    }
    cout << "So luong so duong: " << demduong << endl;
    cout << "So luong so am: " << demam << endl;
    cout << "So luong so khong: " << demkhong << endl;
    return 0;
}
