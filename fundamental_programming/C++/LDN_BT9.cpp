#include <iostream>      
using namespace std;     

int main() {
    int n;
    cout << "Nhap n (so luong so nguyen): ";
    cin >> n;
    int chan = 0, le = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cout << "Nhap so nguyen thu " << i << ": ";
        cin >> a;
        if (a % 2 == 0) {
            chan++;
        } else {
            le++;
        }
    }
    cout << " ket qua BT9" << endl;
    cout << "So luong so chan: " << chan << endl;
    cout << "So luong so le: " << le << endl;
}