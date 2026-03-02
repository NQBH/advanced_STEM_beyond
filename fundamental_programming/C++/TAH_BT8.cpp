#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "nhập n =";
    cin >> n;
    int demAm = 0, demDuong = 0, dem0 = 0;
    if (n <= 0 ) {
        cout << "n la so nguyen duong";
    }
    cout << "Nhap" << n << "so thuc:\n ";
    for (int i = 1; i <= n; i++) {
        float so;
        cout << "a" << i;
        cin >> so;
        if (so > 0 ) {
            demDuong++;
        }
        else if (so < 0) {
            demAm++;
        }
        else {
            dem0++;
        }
    }
    cout << " so duong" << " " << demDuong << endl ;
    cout << " so am" << " " << demAm << endl;
    cout << " so 0" << " " << dem0 <<  endl;
}
