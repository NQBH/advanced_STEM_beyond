#include <bits/stdc++.h>
using namespace std;
int main() {
    int n , m ; cin >> n >> m;
    double S = 0;
    if (n <= 0) {
        cout << "Nhap lai n >= 0" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        S += pow(i, m);
    }
    cout << S;
}