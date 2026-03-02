#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    long long M, Sm = 0;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> M;

    for (int i = 1; i <= n; i++) {
        if (Sm + pow(i, m) > M)
            break;
        Sm = pow(i, m);
    }

    cout << "Sm lon nhat <= M la: " << Sm << endl;

    return 0;
}
