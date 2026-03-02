#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int so;
    int demChan = 0, demLe = 0;

    cout << "Nhap n= ";
    cin >> n;

    if (n <= 0) {
        cout << "n la so nguyen duong: ";
    }

    cout << n;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu" << i;
        cin >> so;
        if (so % 2 == 0) {
            demChan++;
        } else {
            demLe++;
        }
    }
    cout << "so chan co " << demChan << endl;
    cout << "so le co " << demLe << endl;

}
