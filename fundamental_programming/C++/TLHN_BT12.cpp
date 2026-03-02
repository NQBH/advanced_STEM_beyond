#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    double Sm = 0;

    cout << "Nhap n: " << endl;
    cin >> n;

    cout << "Nhap m: " << endl;
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        Sm += pow(i, m);
    }

    cout << Sm;
    return 0;

}
