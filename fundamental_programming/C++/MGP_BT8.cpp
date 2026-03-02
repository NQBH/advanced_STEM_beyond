#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int dd = 0, da = 0, dk = 0;
    double v;
    cout << "n:" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thuc " << i << ":" << endl;
        cin >> v;
        if (v > 0) {
            dd++;
        }
        else if (v < 0) {
            da++;
        }
        else if (v == 0) {
            dk++;
        }
    }
    cout << "Dem so duong:" << dd << endl;
    cout << "Dem so am:" << da << endl;
    cout << "Dem so khong:" << dk << endl;
    return 0;
}
