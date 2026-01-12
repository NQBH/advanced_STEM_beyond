#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cout << "Nhap 3 so a, b, c: ";
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "-1\n";
    }
    else if (a == b && b == c) {
        cout << "HLP\n";
    }
    else {
        cout << "HHCN\n";
        double S_xq = 2 * (a + b) * c;
        cout << "Dien tich xung quanh (voi c la chieu cao): " << S_xq << '\n';
        double S_tp = S_xq + 2 * (a * b);
        cout << "Dien tich toan phan: " << S_tp << '\n';
        double duongCheo = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
        cout << "Duong cheo hinh hop: " << duongCheo << '\n';
        double V = a * b * c;
        cout << "The tich hinh hop: " << V << '\n';
    }

    return 0;
}