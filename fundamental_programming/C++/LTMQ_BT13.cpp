#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    long long M, power;
    cin >> n >> m >> M;

    long long Sm = 0;

    for (int i = 1; i <= n; ++i) {
        long long term = pow(i, m);

        if (Sm + term > M) {
            break;
        }

        Sm += term;
    }

    cout << Sm;
    return 0;
}
