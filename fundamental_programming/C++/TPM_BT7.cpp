#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n: ";
    cin >> n;
    double a[n], vmax, vmin;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vmax = a[0];
    vmin = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > vmax) vmax = a[i];
        if (a[i] < vmin) vmin = a[i];
    }
    cout << "Max: " << vmax << '\n';
    cout << "Min: " << vmin << '\n';
    return 0;
}