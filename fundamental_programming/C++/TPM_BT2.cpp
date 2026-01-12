#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float C, S, duongcheo, cd, cr;
    cout << "Nhap chieu dai " ;
    cin >> cd;
    cout << "Nhap chieu rong " ;
    cin >> cr;
    C = 2 * (cd + cr);
    S = cd * cr;
    duongcheo = sqrt(pow(cd, 2) + pow(cr, 2));
    cout << "Chu vi = " << C << '\n';
    cout << "Dien tich = " << S << '\n';
    cout << "Duong cheo = " << duongcheo << '\n';
    return 0;
}