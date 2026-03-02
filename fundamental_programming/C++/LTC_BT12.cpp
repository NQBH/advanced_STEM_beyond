#include <iostream>
using namespace std;

int main() {
    int n, m;
    long long S = 0;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;

    int i = 1;
    while (i <= n) {
        long long t = 1;
        int j = 1;
        while (j <= m) {
            t *= i;   
            j++;
        }
        S += t;
        i++;
    }

    cout << "Tong Sm = " << S << endl;
    return 0;
}
