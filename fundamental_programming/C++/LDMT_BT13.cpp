#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, m, M;
    long long S = 0;

    cout << "Nhap n, m, M: ";
    cin >> n >> m >> M;

    for (int i = 1; i <= n; i++) {
        long long term = (long long)pow(i, m);
        
        if (S + term > M) {
            break;
        }
        
        S += term;
    }

    cout << "Tong S = " << S << endl;

    return 0;
}