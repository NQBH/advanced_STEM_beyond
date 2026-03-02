#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Nhap n= " << endl;
    cin >> n;

    double a;
    int demSo0 = 0;
    int demSoAm = 0;
    int demSoDuong = 0;


    for (int i = 1; i <= n; i++) {
        cout << " Nhap so a" << i << "= " << endl;
        cin >> a;


        if ( a == 0)
            demSo0++;
        else if (a<0)
            demSoAm++;
        else
            demSoDuong++;
    }

    cout << "So luong so 0: " << demSo0 << endl;
    cout << "So luong so am la: " << demSoAm << endl;
    cout << "So luong so duong la: " << demSoDuong << endl;

    return 0;
}