#include <iostream>
using namespace std;

int main() {
    int n;
    double a;
    int dem0 = 0, demAm = 0, demDuong = 0;

    cout << "so n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "so thu " << i + 1 << ": ";
        cin >> a;

        if (a == 0)
            dem0++;
        else if (a < 0)
            demAm++;
        else
            demDuong++;
    }

    cout << "So luong so 0: " << dem0 << endl;
    cout << "So luong so am: " << demAm << endl;
    cout << "So luong so duong: " << demDuong << endl;

    return 0;
}