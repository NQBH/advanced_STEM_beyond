#include <iostream>
using namespace std;

int main() {
    double a, b, c, vmax, vmin;
    cin >> a >> b >> c;
    vmax = a;
    vmin = c;
    if (b > vmax) vmax = b;
    if (c > vmax) vmax = c;
    if (a < vmin) vmin = a;
    if (b < vmin) vmin = b;
    cout << "so lon nhat la: " << vmax << endl;
    cout << "so be nhat la: " << vmin << endl;
    cout << "nhap so n: ";
    int n, d; cin >> n;
    cout << "hay nhap " << n << " so thuc" << endl;
    cin >> d;
    vmax = vmin = d;
    for (int i = 1; i <= (n - 1); ++i) {
        cin >> d;
        if (d > vmax) vmax = d;
        if (d < vmin) vmin = d;
    }
    cout << vmax << endl;
    cout << vmin << endl;
}