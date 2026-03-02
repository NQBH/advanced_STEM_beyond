#include<iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    int dem0 = 0;
    int demAm = 0;
    int demDuong = 0;
    double x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            dem0++;
        }
        else if (x < 0) {
            demAm++;
        } else {
            demDuong++;
        }
    }
    cout << "Tong so 0: " << dem0 << endl;
    cout << "Tong so am: " << demAm << endl;
    cout << "Tong so duong: " << demDuong << endl;
}