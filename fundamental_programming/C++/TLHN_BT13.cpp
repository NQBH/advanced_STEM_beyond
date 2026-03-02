#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int m;
    double M;
    double Sm = 0;   // Sm khởi tạo = 0

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap m: ";
    cin >> m;

    cout << "Nhap M: ";
    cin >> M;

    for (int i = 1; i <= n; ++i) {
        double t = pow(i, m);

        if (Sm + t > M) break;

        Sm += t;
    }

    cout << "Sm = " << Sm << endl;

    return 0;
}
