#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long m, n, M;
    cin >> m >> n >> M;
    long long S = 0;
    long long i = 1;
    while (i <= n) {
        long long s = pow(i, m);
        if (S + s <= M) {
            S += s;
            i++;
        } else {
            break;
        }
    }
    cout << S;
}