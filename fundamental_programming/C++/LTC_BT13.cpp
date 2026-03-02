#include <iostream>
using namespace std;

int main() {
    int n, m;
    long long M;
    long long S = 0;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> M;

    int i = 1;
    while (i <= n) {
        long long t = 1;
        int j = 1;

        while (j <= m) {
            t *= i;
            j++;
        }

        if (S + t > M) {
            break;
        }

        S += t;
        i++;
    }

    cout << "Tong Sm lon nhat <= M la: " << S << endl;
    return 0;
}
