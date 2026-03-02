#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    long long Sm = 0;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    for (int i = 1; i <= n; i++) {
        Sm += pow(i, m);
    }
    cout << "Sm = " << Sm;
    return 0;
}
