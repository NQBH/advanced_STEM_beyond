#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long Sm = 0;
    long long M;
    int m, n = 0;


    cout << "Nhap m " << endl;
    cin >> m;

    cout << "Nhap M ( M la gia tri lon nhat ) " << endl;
    cin >> M;

    for ( int i = 1; ; i++ ) {
        long long p = pow(i, m);

        if (Sm + p > M) {
            n = i - 1;
            break;
        }

        Sm += p;
        n = i;
    }

    cout << "n lon nhat = " << n << endl;
    cout << "Sm = " << Sm << endl;

    return 0;
}
