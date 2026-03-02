#include <iostream>      
using namespace std;     

int main() {
    int n;
    cout << "nhap n (so luong so thuc): ";
    cin >> n;
    int am = 0, duong = 0, zero = 0;
    for (int i = 1; i <= n; ++i) {
        double a;
        cout << "nhap so thuc thu " << i << ": ";
        cin >> a;
        if (a > 0)
        duong++;
        else if (a < 0)
        am++;
        else
        zero++;

    }
    cout << "ket qua BT8" << endl;
    cout << "so luong so duong: " << duong << endl;
    cout << "so luong so am: " << am << endl;
    cout << "so luong so khong: " << zero << endl;
}
