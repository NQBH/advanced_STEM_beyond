#include <iostream>
using namespace std;

int main() {
    int n;
    float a;
    int demAm = 0, demDuong = 0, demKhong = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a > 0)
            demDuong++;
        else if (a < 0)
            demAm++;
        else
            demKhong++;
    }
    cout << "So so am: " << demAm << endl;
    cout << "So so duong: " << demDuong << endl;
    cout << "So so 0: " << demKhong << endl;

    return 0;
}
