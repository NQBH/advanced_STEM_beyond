#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n;
    cout << " Nhap vao phan tu n";
    cin >> n;
    int demchan = 0;
    int demle = 0;
    int i = 1;
    int x;
lap:
    if ( i > n ) {
        goto ketthuc;
    }
    cout << "Nhap so nguyen thu " << i << endl;
    cin >> x;
    if ( x % 2 == 0) {
        demchan = demchan + 1;
    }
    else {
        demle = demle + 1;
    }
    i = i + 1;
    goto lap;
ketthuc:
    cout << "------------------------" << endl;
    cout << " So phan tu chan la:" << demchan << endl;
    cout << " So phan tu le la:" << demle << endl;
    return 0;
}