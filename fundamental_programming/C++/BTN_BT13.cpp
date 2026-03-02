#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int m;
    long long M_limit;
    long long Sm = 0;
    int n = 0;
    cout << "Nhap m (so mu): ";
    cin >> m;
    cout << "Nhap M (nguong gioi han): ";
    cin >> M_limit;
    while (true) {
        long long tiep_theo = pow(n + 1, m);
        if (Sm + tiep_theo <= M_limit) {
            n++;
            Sm += tiep_theo;
        } else {
            break;
        }
    }
    cout << "--- Ket qua ---" << endl;
    cout << "Gia tri n lon nhat thoa man la: " << n << endl;
    cout << "Tong Sm tuong ung la: " << Sm << " (<= " << M_limit << ")" << endl;

    return 0;
}