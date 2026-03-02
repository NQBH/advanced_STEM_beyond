#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n;
    cout << "Nhap phan tu n:";
    cin >> n;
    int demduong = 0;
    int demam = 0;
    int dem0 = 0;
    int i = 1;
    double x;
lap:
    if ( i > n ) {
        goto ketthuc;
    }
    cout << " Nhap so thuc thu:" << i << ":" << endl;
    cin >> x;
    if ( x > 0 ) {
        demduong = demduong + 1;
    }
    else if (x < 0 ) {
        demam = demam + 1;
    }
    else {
        dem0 = dem0 + 1;
    }
    i = i + 1;
    goto lap;
ketthuc:
    cout << " -------------------------" << endl;
    cout << " So phan tu duong la:" << demduong << endl;
    cout << " So phan tu am la:" << demam << endl;
    cout << " So phan tu 0 la:" << dem0 << endl;
    return 0;
}
