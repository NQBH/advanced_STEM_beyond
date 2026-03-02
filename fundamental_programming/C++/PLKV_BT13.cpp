#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    long long M;
    long long Sm = 0;

    cout << "Nhap n:";
    cin >> n;
    cout << "Nhap m:";
    cin >> m;
    cout << "Nhap M:";
    cin >> M;

    for (int i = 1; i <= n; ++i) {
        long long giatri = pow(i, m); //giatri i^M
        if (Sm + giatri <= M) {
            Sm += giatri;
        } else {
            break;
        }
    }
    cout << "gia tri Sm lon nhat (<= M) la :" << Sm << endl;
}