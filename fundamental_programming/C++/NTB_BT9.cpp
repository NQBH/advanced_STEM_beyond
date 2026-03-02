#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "nhap n: ";
    cin >> n;
    int v[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int chan, le;
    chan = 0;
    le = 0;
    for ( int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) {chan++;}
        else le++;
    }
    cout << "vay tong so chan la: " << chan << endl;
    cout << "vay tong so le la: " << le << endl;
}