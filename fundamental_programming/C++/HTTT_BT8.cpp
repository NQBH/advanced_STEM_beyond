#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int demsoso0 = 0, demsosoAm = 0, demsosoDuong = 0;
    float a;

    for (int i = 1; i <= n; ++i) {
        cout << "Nhap so thu " << i << ": ";
        cin >> a;

        if (a > 0)
            demsosoDuong++;
        else if (a < 0)
            demsosoAm++;
        else
            demsoso0++;
    }

    cout << "So so duong: " << demsosoDuong << endl;
    cout << "So so am: " << demsosoAm << endl;
    cout << "So so bang 0: " << demsoso0 << endl;

    return 0;
}
