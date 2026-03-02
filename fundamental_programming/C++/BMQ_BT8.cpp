#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a;
    int dem0 = 0, demAm = 0, demDuong = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 0) dem0++;
        else if (a < 0) demAm++;
        else demDuong++;
    }

    cout << "So 0: " << dem0 << endl;
    cout << "So am: " << demAm << endl;
    cout << "So duong: " << demDuong << endl;
    return 0;
}
