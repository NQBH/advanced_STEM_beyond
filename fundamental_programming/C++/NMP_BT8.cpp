#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dem0 = 0, demAm = 0, demDuong = 0;
    double a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) dem0++;
        else if (a < 0) demAm++;
        else demDuong++;
    }

    cout << dem0 << endl;
    cout << demAm << endl;
    cout << demDuong << endl;
    return 0;
}