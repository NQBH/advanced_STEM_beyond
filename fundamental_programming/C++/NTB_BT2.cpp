#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float Cd, Cr, S, Cv, Dc;
    cout << "nhap chieu dai: ";
    cin >> Cd;
    cout << "nhap chieu rong: ";
    cin >> Cr;
    S = Cd * Cr;
    Cv = (Cd + Cr) * 2;
    Dc = sqrt(pow(Cd, 2) + pow(Cr, 2));
    cout << " vay dien tich hcn la:" << S << endl;
    cout << " vay chu vi hcn la:" << Cv << endl;
    cout << " vay duong cheo hcn la: " << Dc << endl;
    return 0;
}