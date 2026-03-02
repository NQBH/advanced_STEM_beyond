#include <iostream>
using namespace std;
int main() {
    int n, duong, am, zr;
    float a;
    cout << "n = ";
    cin >> n;
    duong = am = zr = 0;
    for (int i = 1 ; i <= n; ++i) {
        cin >> a;
        if (a > 0) duong++;
        else if (a < 0) am++;
        else zr++;
    }
    cout << "so cac so duong la " << duong << endl;
    cout << "so cac so am la " << am << endl;
    cout << "so cac so 0 la " << zr << endl;
}