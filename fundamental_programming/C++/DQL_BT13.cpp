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
        long long term = pow(i, m);
        if (Sm + term > M) {
            break;
        }
        Sm += term;
    }

    cout << "Gia tri Sm lon nhat <= M la: " << Sm;

    return 0;
}