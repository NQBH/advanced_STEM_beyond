#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n, m;
    long long M;
    long long Sm = 0;
    
    cout << "Nhap n =";
    cin >> n;
    cout << "Nhap m =";
    cin >> m;
    cout << "Nhap M =";
    cin >> M;
    
    for (int i = 1; i <= n; ++i) {
        long long soHang = pow(i,m); // soHang la i^M
        if (Sm + soHang <= M) {
            Sm += soHang;
        } else {
            break;
        }
    }
    cout << "Gia tri Sm lon nhat (<= M) la :" << Sm << endl;
    return 0;
}