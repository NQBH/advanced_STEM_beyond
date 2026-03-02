#include <iostream>
using namespace std;

double smax(double a, double b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int n, chan, le;
    cout << "n: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    chan = 0;
    le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            chan++;
        } else le++;
    }
    cout << "Số số lẻ: " << le << '\n';
    cout << "Số số chẵn: " << chan << '\n';
    return 0;
}
