#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "n bang= ";
    cin >> n;
    int dem0 = 0, demAm = 0, demDuong = 0;
    double x;

    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x == 0) dem0++;
        else if (x < 0) demAm++;
        else demDuong++;
    }
    cout << "Day la so so 0= " << dem0 << endl;
    cout << "Day la so so am= " << demAm << endl;
    cout << "Day la so so duong= " << demDuong << endl;

    return 0;
}