#include <iostream>
using namespace std;

int main() {
    int n;
    int so;
    int demChan = 0, demLe = 0;

    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Sai: n phai la so nguyen duong: ";
    }

    cout << "Nhap " << n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i;
        cin >> so;
        if (so % 2 == 0) {
            demChan++;
        } else {
            demLe++;
        }
    }
    cout << "So luong so chan: " << demChan << endl;
    cout << "So luong so le: " << demLe << endl;

}