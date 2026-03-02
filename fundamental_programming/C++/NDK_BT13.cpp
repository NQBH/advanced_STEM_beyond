#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n , m , M;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> M;
    double S = 0;
    for ( int i = 1; i <= n; ++i) {
        double sotieptheo = pow(i, m);

        if (S + sotieptheo <= M) {
            S += sotieptheo;
        } else {
            break;
        }
    }
    cout << "Gia tri lon nhat khong vuot qua M la: " << S << endl;
    return 0;
}
